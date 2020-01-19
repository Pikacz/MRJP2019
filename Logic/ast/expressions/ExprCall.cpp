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
    throw ExpectedFunctionType(func->getLine(), func->getColumn(), lhsT);
}


ExprCall::ExprCall(
    size_t line,
    size_t column,
    Environment * env,
    unique_ptr<const Expression> _func,
    vector<unique_ptr<const Expression>> _params
) noexcept(false): func(move(_func)), params(move(_params)), Expression(getReturnType(_func.get()), line, column) {
    
    auto fType = dynamic_cast<FunctionType const *>(func.get()->getType());
    
    auto paramsT = fType->getParameters();
    
    if (paramsT.size() != params.size()) {
        throw InvalidNumberOfParameters(
            line, column, fType, params.size()
        );
    }
    
    for (size_t i = 0; i < params.size(); ++i) {
        if (! params[i].get()->isKindOf(paramsT[i])) {
            throw InvalidType(
                params[i].get()->getLine(),
                params[i].get()->getColumn(),
                paramsT[i],
                params[i].get()->getType()
            );
        }
    }
    
    env->markFuncCall(params.size());
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
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    static vector<AsmRegister::Type> paramRegs = {
        AsmRegister::Type::rdi,
        AsmRegister::Type::rsi,
        AsmRegister::Type::rdx,
        AsmRegister::Type::rcx,
        AsmRegister::Type::r8,
        AsmRegister::Type::r9
    };
    
    if (params.size() > paramRegs.size()) {
        handler.freeRegister(
            AsmRegister::Type::r10,
            type,
            compiled
        );
    }
    
    
    for (size_t i = 0; i < params.size(); ++i) {
        if (i < paramRegs.size()) {
            if (destination != paramRegs[i]) {
                handler.freeRegister(paramRegs[i], type, compiled);
            }
            
            params[i]->compile(type, compiled, env, handler, lblHandler, paramRegs[i]);
            if (params[i]->getType()->isKindOf(env->getLatteString())) {
                
            }
        } else {
            params[i]->compile(type, compiled, env, handler, lblHandler, AsmRegister::Type::r10);
            compiled.push_back(
                make_unique<AsmPush>(
                    type,
                    make_unique<AsmRegister>( AsmRegister::Type::r10)
                )
            );
        }
    }
    
    if (params.size() < paramRegs.size()) {
        for (size_t i = params.size(); i < paramRegs.size(); ++i) {
            if (destination != paramRegs[i]) {
                handler.freeRegister(paramRegs[i], type, compiled);
            }
        }
    }
    
    if (destination != AsmRegister::Type::rbx) {
        handler.freeRegister(AsmRegister::Type::rbx, type, compiled);
    }
    if (destination != AsmRegister::Type::rax) {
        handler.freeRegister(AsmRegister::Type::rax, type, compiled);
    }
    func->compileCall(type, compiled, env, handler, lblHandler);
    
    if (destination != AsmRegister::Type::rax) {
        compiled.push_back(
            make_unique<AsmMov>(
                type,
                make_unique<AsmRegister>(AsmRegister::Type::rax),
                make_unique<AsmRegister>(destination)
            )
        );
        handler.restoreRegister(AsmRegister::Type::rax, type, compiled);
    }
    if (destination != AsmRegister::Type::rbx) {
        handler.restoreRegister(AsmRegister::Type::rbx, type, compiled);
    }
    
    if (params.size() < paramRegs.size()) {
        for (size_t i = params.size(); i < paramRegs.size(); ++i) {
            if (destination != paramRegs[i]) {
                handler.restoreRegister(paramRegs[i], type, compiled);
            }
        }
    }
    
    for (size_t _i = params.size(); _i > 0; --_i) {
        size_t i = _i - 1;
        if (i < paramRegs.size()) {
            if (destination != paramRegs[i]) {
                handler.restoreRegister(paramRegs[i], type, compiled);
            }
        } else {
            compiled.push_back(
                make_unique<AsmPop>(
                    type,
                    make_unique<AsmRegister>(AsmRegister::Type::r10)
                )
            );
        }
    }
    
    
    if (params.size() > paramRegs.size()) {
        handler.restoreRegister(
            AsmRegister::Type::r10,
            type,
            compiled
        );
    }
    
}
