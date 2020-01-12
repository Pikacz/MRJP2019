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
#include "../assembler/values/AsmMemory.hpp"

#include "function/Function.hpp"
#include "function/FunctionInitializer.hpp"

using namespace std;


FunctionEnvironment::FunctionEnvironment(
    Environment const * parent,
    FunctionInitializer initializer,
    bool isMain
) noexcept: isMain(isMain), BlockEnvironment(parent) {}


// MARK: - variables
void FunctionEnvironment::declareParameterVariable(
    string name,
    Type const * type,
    size_t line,
    size_t column
) noexcept(false) {
    const string key = keyForVariableNamed(name);
    for (size_t i = 0; i <= parameters.size(); ++i) {
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
    for (size_t i = 0; i <= parameters.size(); ++i) {
        if (parameters[i].first == key) {
            return parameters[i].second.get();
        }
    }
    return parent->getVariableNamed(name, line, column);
}


int FunctionEnvironment::getSize() const noexcept {
    int result = BlockEnvironment::getSize();
    if (isMain) {
        result += 4;
    }
    
    return result;
}


int FunctionEnvironment::requiredSpace() const noexcept {
    return getSize() + childMaxSize();
}

void FunctionEnvironment::initializeVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    BlockEnvironment::initializeVariables(compiled);
}


void FunctionEnvironment::cleanVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    BlockEnvironment::cleanVariables(compiled);
    int mySpace = getSize();
    int childrenSpace = childMaxSize() + mySpace;
    compiled.push_back(
        make_unique<AsmAdd>(
            AssemblerValue::Size::bit64,
            make_unique<AsmIntConstant>(childrenSpace),
            make_unique<AsmRegister>(AsmRegister::rsp)
        )
    );
    compiled.push_back(
        make_unique<AsmPop>(
            AssemblerValue::Size::bit64,
            make_unique<AsmRegister>(AsmRegister::rsp)
        )
    );
}


void FunctionEnvironment::compileVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    int mySpace = getSize();
    
    int childrenSpace = childMaxSize();
    int myFirst = childrenSpace + mySpace;
    if (isMain) {
        myFirst -= 4;
    }
    
    
    compiled.push_back(
        make_unique<AsmPush>(
            AssemblerValue::Size::bit64,
            make_unique<AsmRegister>(AsmRegister::rsp)
        )
    );
    
    compiled.push_back(
        make_unique<AsmSub>(
            AssemblerValue::Size::bit64,
            make_unique<AsmIntConstant>(mySpace + childrenSpace),
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
                    myFirst,
                    make_unique<AsmRegister>(AsmRegister::rbp),
                    nullopt,
                    AsmMemory::ScaleT::one
                )
            )
        );
    }
    setVariables(compiled, myFirst);
    for (auto & child : children) {
        child->setVariables(compiled, child->getSize());
    }
}
