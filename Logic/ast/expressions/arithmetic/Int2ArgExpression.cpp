//
//  Int2ArgExpression.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "Int2ArgExpression.hpp"

#include "../../../staticCheck/types/InvalidType.hpp"
#include "../../../assembler/instructions/AsmMov.hpp"
#include "../../../assembler/values/registers/AsmRegister.hpp"

using namespace std;

Int2ArgExpression::Int2ArgExpression(
    Environment const * env,
    size_t line,
    size_t column,
    unique_ptr<const Expression> _lhs,
    unique_ptr<const Expression> _rhs
) noexcept(false): Expr2Arg(env->getLatteInt(), line, column, move(_lhs), move(_rhs)) {
    auto lType = this->lhs.get()->getType();
    if (!lType->isKindOf(env->getLatteInt())) {
        throw InvalidType(
            this->lhs.get()->getLine(),
            this->lhs.get()->getColumn(),
            env->getLatteInt(),
            lType
        );
    }
    
    
    auto rType = this->rhs.get()->getType();
    if (!rType->isKindOf(env->getLatteInt())) {
        throw InvalidType(
            this->rhs.get()->getLine(),
            this->rhs.get()->getColumn(),
            env->getLatteInt(),
            rType
        );
    }
}



void Int2ArgExpression::compile(
    AssemblerValue::Size type,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmRegister::Type destination
) const noexcept {
    auto lPos = lhsPosition(destination, handler);
    auto rPos = rhsPosition(destination, handler, lPos);
    
    if (lPos != destination) {
        handler.freeRegister(lPos, type, compiled);
    }
    lhs.get()->compile(type, compiled, env, handler, lPos);
    // w lPos mam lewą stronę
    
    if (rPos != destination) {
        handler.freeRegister(rPos, type, compiled);
    }
    
    handler.freeRegister(lPos, type, compiled);
    rhs.get()->compile(type, compiled, env, handler, rPos);
    // w lPos mam cokolwiek
    // w rPos mam prawą stronę
    handler.restoreRegister(lPos, type, compiled);
    
    // w lPos mam lewą stronę
    // w rPos mam prawą stronę
    
    
    calculate(compiled, handler, type, lPos, rPos, destination);
    
    // w destination mam wynik
    // w lPos mam lewą stronę
    // w rPos mam prawą stronę
    
    if (rPos != destination) {
        handler.restoreRegister(rPos, type, compiled);
    }
    // w destination mam wynik
    // w lPos mam lewą stronę
    // w rPos mam to co wczesniej
    if (lPos != destination) {
        handler.restoreRegister(lPos, type, compiled);
    }
    // w destination mam wynik
    // w lPos mam to co wczesniej
    // w rPos mam to co wczesniej
}
