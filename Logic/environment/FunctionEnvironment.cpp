//
//  FunctionEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "FunctionEnvironment.hpp"

#include "../staticCheck/redeclaration/VariableRedeclarationError.hpp"

#include "../assembler/values/AsmIntConstant.hpp"
#include "../assembler/instructions/AsmAdd.hpp"
#include "../assembler/instructions/AsmSub.hpp"
#include "../assembler/instructions/AsmMov.hpp"
#include "../assembler/instructions/AsmPop.hpp"
#include "../assembler/instructions/AsmPush.hpp"
#include "../assembler/instructions/AsmCall.hpp"
#include "../assembler/values/AsmMemory.hpp"
#include "../assembler/GarbageCollector.hpp"

#include "../ast/expressions/VarExpression.hpp"

#include "function/Function.hpp"
#include "function/FunctionInitializer.hpp"

#include <sstream>

#include <cassert>

using namespace std;


FunctionEnvironment::FunctionEnvironment(
    Environment const * parent,
    FunctionInitializer initializer,
    bool isMain
) noexcept(false): isMain(isMain), BlockEnvironment(parent) {
    
    for (auto & param : initializer.getParameters()) {
        declareParameterVariable(param.name, param.type, param.line, param.column);
    }
}


// MARK: - variables
void FunctionEnvironment::declareParameterVariable(
    string name,
    Type const * type,
    size_t line,
    size_t column
) noexcept(false) {
    const string key = keyForVariableNamed(name);
    for (size_t i = 0; i < parameters.size(); ++i) {
        if (parameters[i].first == key) {
            throw VariableRedeclarationError(line, column, name);
        }
    }
    parameters.push_back(make_pair(key, make_unique<Variable>(type, this)));
}



Variable const * FunctionEnvironment::getVariableNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        return search->second.get();
    }
    for (size_t i = 0; i < parameters.size(); ++i) {
        if (parameters[i].first == key) {
            return parameters[i].second.get();
        }
    }
    return parent->getVariableNamed(name, line, column);
}


void FunctionEnvironment::declareFakeVariables(size_t count) noexcept {
    for (size_t i = 0; i < count; ++i) {
        stringstream ss;
        ss << " fake var " << i;
        string nm = ss.str();
        declareVariable(nm, getLatteInt(), -1, -1);
        fakeVars[nm] = make_pair(getVariableNamed(nm, -1, -1), true);
    }
}


Variable const * FunctionEnvironment::getNextFakeVariable() const noexcept {
    for (auto it = fakeVars.begin(); it != fakeVars.end(); ++it) {
        if (it->second.second) {
            it->second.second = false;
            return it->second.first;
        }
    }
    
    assert(false);
}


void FunctionEnvironment::releaseFakeVariable(
    Variable const * var,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) const noexcept {
    AsmRegister::Type reg;
    auto r = handler.anyFreeNotEqual(AsmRegister::Type::rax);
    if (r != nullopt) {
        reg = *r;
    } else {
        handler.freeRegister(
            AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled
        );
        reg = AsmRegister::Type::rax;
    }
    
    auto varExpr = make_unique<VarExpression>(-1, -1, var);
    varExpr->compile(
        AssemblerValue::Size::bit64, compiled, this, handler, lblHandler, reg
    );
    
    GarbageCollector::decCounter(reg, compiled, this, handler, lblHandler);
    
    
    if (r == nullopt) {
        handler.restoreRegister(
            AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled
        );
    }
    
    for (auto it = fakeVars.begin(); it != fakeVars.end(); ++it) {
        if (it->second.first == var) {
            it->second.second = true;
            return;
        }
    }
    
    assert(false);
}

size_t FunctionEnvironment::getSize() const noexcept {
    size_t result = BlockEnvironment::getSize();
    if (isMain) {
        result += 8;
    }
    for (size_t i = 0; i < parameters.size(); ++i) {
        result += 8;
    }
    
    return result;
}

void FunctionEnvironment::setVariables(
    size_t firstAt
) const noexcept {
    
    for (auto& it : parameters) {
        firstAt -= it.second.get()->getType()->pointerSize();
        it.second.get()->setMemory(
            make_unique<AsmMemory>(
                firstAt,
                make_unique<AsmRegister>(AsmRegister::Type::rbp),
                nullopt,
                AsmMemory::ScaleT::one
            )
        );
    }
    
    BlockEnvironment::setVariables(firstAt);
}


void FunctionEnvironment::initializeVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    BlockEnvironment::initializeVariables(compiled);
}


void FunctionEnvironment::cleanVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) const noexcept {
    BlockEnvironment::cleanVariables(compiled, handler, lblHandler);
    
    if (isMain) {
        
        handler.freeRegister(AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled);
        
        compiled.push_back(
            make_unique<AsmCall>(
                AssemblerValue::Size::bit64, "__Z11checkDeletev"
            )
        );
        
        handler.restoreRegister(AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled);
    }
    
    
    size_t myFirst = getSize() + getFuncParams();
    
    if (myFirst % 16 != 0) {
        myFirst += 8;
    }
    
    compiled.push_back(
        make_unique<AsmAdd>(
            AssemblerValue::Size::bit64,
            make_unique<AsmIntConstant>(myFirst),
            make_unique<AsmRegister>(AsmRegister::rsp)
        )
    );
    compiled.push_back(
        make_unique<AsmPop>(
            AssemblerValue::Size::bit64,
            make_unique<AsmRegister>(AsmRegister::rbp)
        )
    );
}


void FunctionEnvironment::compileVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler
) const noexcept {
    size_t myFirst = getSize() + getFuncParams();
    
    if (myFirst % 16 != 0) {
        myFirst += 8;
    }
    
    compiled.push_back(
        make_unique<AsmPush>(
            AssemblerValue::Size::bit64,
            make_unique<AsmRegister>(AsmRegister::rbp)
        )
    );
    
    compiled.push_back(
        make_unique<AsmSub>(
            AssemblerValue::Size::bit64,
            make_unique<AsmIntConstant>(myFirst),
            make_unique<AsmRegister>(AsmRegister::rsp)
        )
    );
    compiled.push_back(
        make_unique<AsmMov>(
            AssemblerValue::Size::bit64,
            make_unique<AsmRegister>(AsmRegister::rsp),
            make_unique<AsmRegister>(AsmRegister::rbp)
        )
    );
    
    
    if (isMain) {
        compiled.push_back(
            make_unique<AsmMov>(
                AssemblerValue::Size::bit32,
                make_unique<AsmIntConstant>(0),
                make_unique<AsmMemory>(
                    myFirst - 4,
                    make_unique<AsmRegister>(AsmRegister::rbp),
                    nullopt,
                    AsmMemory::ScaleT::one
                )
            )
        );
        myFirst -= 8;
    }
    setVariables(myFirst);
    compileParameters(compiled, handler);
}


void FunctionEnvironment::compileParameters(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler
) const noexcept {
    static vector<AsmRegister::Type> paramRegs = {
        AsmRegister::Type::rdi,
        AsmRegister::Type::rsi,
        AsmRegister::Type::rdx,
        AsmRegister::Type::rcx,
        AsmRegister::Type::r8,
        AsmRegister::Type::r9
    };
    
    for (size_t i = parameters.size(); i > 0; --i) {
        size_t idx = i - 1;
        auto address = parameters[idx].second->getAddress(
            AssemblerValue::Size::bit64, compiled, this, handler
        );
        if (idx < paramRegs.size()) {
            compiled.push_back(
                make_unique<AsmMov>(
                    AssemblerValue::Size::bit64,
                    make_unique<AsmRegister>(paramRegs[idx]),
                    move(address)
                )
            );
        } else {
            compiled.push_back(
                make_unique<AsmPop>(AssemblerValue::Size::bit64, move(address))
            );
        }
    }
}
