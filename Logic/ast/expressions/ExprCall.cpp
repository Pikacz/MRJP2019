//
//  ExprCall.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprCall.hpp"

#include "../../environment/types/FunctionType.hpp"
#include "../../staticCheck/types/ExpectedFunctionType.hpp"
#include "../../staticCheck/types/InvalidNumberOfParameters.hpp"
#include "../../staticCheck/types/InvalidType.hpp"
#include "VarExpression.hpp"
#include "../../assembler/values/registers/AsmRegister.hpp"
#include "../../assembler/instructions/AsmPop.hpp"
#include "../../assembler/instructions/AsmPush.hpp"
#include "../../assembler/instructions/AsmMov.hpp"
#include "../../assembler/GarbageCollector.hpp"


using namespace std;



static Type const * getReturnType(
    Expression const * func
) noexcept(false) {
    auto lhsT = func->getType();
    
    if (auto fType = dynamic_cast<FunctionType const *>(lhsT)) {
        return fType->getReturnType();
    }
    throw ExpectedFunctionType(func->getLine(), func->getColumn(), lhsT->getName());
}


ExprCall::ExprCall(
    size_t line,
    size_t column,
    unique_ptr<const Expression> _func,
    vector<unique_ptr<const Expression>> _params
) noexcept(false): func(move(_func)), params(move(_params)), Expression(getReturnType(_func.get()), line, column) {
    
    auto fType = dynamic_cast<FunctionType const *>(func.get()->getType());
    
    auto paramsT = fType->getParameters();
    
    if (paramsT.size() != params.size()) {
        throw InvalidNumberOfParameters(
            line, column, fType->getName(), fType->getParameters().size(), params.size()
        );
    }
    
    for (size_t i = 0; i < params.size(); ++i) {
        if (! params[i].get()->isKindOf(paramsT[i])) {
            throw InvalidType(
                params[i].get()->getLine(),
                params[i].get()->getColumn(),
                paramsT[i]->getName(),
                params[i].get()->getType()->getName()
            );
        }
    }
}



bool ExprCall::isTerminating() const noexcept {
    if (auto varExpr = dynamic_cast<VarExpression const *>(func.get())) {
        return varExpr->isLatteErrorFunc();
    }
    return false;
}


bool ExprCall::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprCall const *>(node)) {
        if (params.size() != nd->params.size()) {
            return false;
        }
        for (size_t i = 0; i < params.size(); ++i) {
            if (!params[i]->isEqualTo(nd->params[i].get())) {
                return false;
            }
        }
        return func->isEqualTo(nd->func.get());
    }
    return false;
}


void ExprCall::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & _handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    // zachowaj używane rejestry
    vector<AsmRegister::Type> regsToSave = _handler.allUsedRegisters();
    
    for (size_t i = 0; i < regsToSave.size(); ++i) {
        if (regsToSave[i] != destination) {
            _handler.freeRegister(
                regsToSave[i], type, compiled
            );
        }
    }
    // w tym momencie mamy czystego enva rejestrów
    AsmRegistersHandler handler;
    
    // skompiluj usuwalne parametry do fikcyjnych zmiennych
    vector<Variable const *> fakeVariables;
    vector<unique_ptr<VarExpression>> fakeVarExprs;
    
    
    for (size_t i = 0; i < params.size(); ++i) {
        if (params[i]->getType()->isPointer()) {
            handler.freeRegister(
                AsmRegister::Type::rdi, type, compiled
            );
            params[i]->compile(
                type,
                compiled,
                env,
                handler,
                lblHandler,
                AsmRegister::Type::rdi
            );
            handler.restoreRegister(
                AsmRegister::Type::rdi, AssemblerValue::Size::bit64, compiled
            );
            auto var = env->getNextFakeVariable();
            fakeVariables.push_back(var);
            fakeVarExprs.push_back(make_unique<VarExpression>(-1, -1, var));
            fakeVarExprs.back()->saveValueFrom(
                AsmRegister::Type::rdi, type,
                compiled, env, handler
            );
        }
    }
    
    
    // wylicz parametry funckcji
    static vector<AsmRegister::Type> paramRegs = {
        AsmRegister::Type::rdi,
        AsmRegister::Type::rsi,
        AsmRegister::Type::rdx,
        AsmRegister::Type::rcx,
        AsmRegister::Type::r8,
        AsmRegister::Type::r9
    };
    
    size_t var_i = 0;
    AsmRegister::Type d;
    for (size_t i = 0; i < params.size(); ++i) {
        if (i < paramRegs.size()) {
            d = paramRegs[i];
            // jeśli ktoś w przyszłości weźmie tę wartość to musi mi ją oddac
            handler.freeRegister(d, AssemblerValue::Size::bit64, compiled);
        } else {
            d = AsmRegister::Type::r10;
        }
        
        if (params[i]->getType()->isPointer()) {
            fakeVarExprs[var_i]->loadValueInto(
                d, type, compiled, env, handler
            );
            var_i++;
        } else {
            params[i]->compile(type, compiled, env, handler, lblHandler, d);
        }
        
        if (i >= paramRegs.size()) {
            compiled.push_back(
                make_unique<AsmPush>(
                    type,
                    make_unique<AsmRegister>(d)
                )
            );
        }
    }
    
    // wykonaj call
    func->compileCall(type, compiled, env, handler, lblHandler);
    
    if (destination != AsmRegister::Type::rax) {
        compiled.push_back(
            make_unique<AsmMov>(
                type,
                make_unique<AsmRegister>(AsmRegister::Type::rax),
                make_unique<AsmRegister>(destination)
            )
        );
    }
    
    // oczyść fikcyjne zmienne
    if (fakeVariables.size() > 0) {
        for (size_t i = 0; i < 2; ++i) {
            compiled.push_back(
                make_unique<AsmPush>(
                    type,
                    make_unique<AsmRegister>(destination)
                )
            );
        }
        AsmRegistersHandler handler2;
        for (auto &fVar : fakeVariables) {
            env->releaseFakeVariable(fVar, compiled, handler2, lblHandler);
        }
        
        for (size_t i = 0; i < 2; ++i) {
            compiled.push_back(
                make_unique<AsmPop>(
                    type,
                    make_unique<AsmRegister>(destination)
                )
            );
        }
    }
    
    
    // przywróć rejestry sprzed calla
    for (size_t ii = regsToSave.size(); ii > 0; --ii) {
        size_t i = ii - 1;
        if (regsToSave[i] != destination) {
            _handler.restoreRegister(
                regsToSave[i], AssemblerValue::Size::bit64, compiled
            );
        }
    }
    
}

#include <iostream>

size_t ExprCall::fakeVariablesCount() const noexcept {
    size_t result = 0;
    size_t pointers = 0;
    size_t store_previous_and_calc;
    
    for (size_t i = 0; i < params.size(); ++i) {
        if (params[i]->getType()->isPointer()) {
            store_previous_and_calc = pointers + params[i]->fakeVariablesCount();
            pointers++;
        } else {
            store_previous_and_calc = 0;
        }
        size_t store_results = pointers;
        
        result = max(
            store_previous_and_calc,
            store_results
        );
    }
    
    return result;
}
