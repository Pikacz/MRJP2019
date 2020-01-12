//
//  CompareExpr.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CompareExpr.hpp"

#include "../../../../staticCheck/types/InvalidType.hpp"
#include "../../constants/BoolConstant.hpp"
#include "../../../../assembler/instructions/AsmJmp.hpp"
#include "../../../../assembler/instructions/AsmJne.hpp"
#include "../../../../assembler/instructions/AsmJe.hpp"
#include "../../../../assembler/instructions/AsmCmp.hpp"
#include "../../../../assembler/instructions/AsmMov.hpp"

using namespace std;

CompareExpr::CompareExpr(
    Environment const * env,
    size_t line,
    size_t column,
    unique_ptr<const Expression> _lhs,
    unique_ptr<const Expression> _rhs
) noexcept(false): Expr2Arg(env->getLatteBool(), line, column, move(_lhs), move(_rhs)) {
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


void CompareExpr::compile(
    AssemblerValue::Size type,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    auto resultTrue = lblHandler.getNextLbl();
    auto resultFalse = lblHandler.getNextLbl();
    auto end = lblHandler.getNextLbl();
    
    
    
    AsmRegister::Type tmp;
    auto _tmp = handler.anyFreeNotEqual(destination);
    if (_tmp != nullopt) {
        tmp = *_tmp;
    } else if (destination != AsmRegister::Type::rax) {
        tmp = AsmRegister::Type::rax;
    } else {
        tmp = AsmRegister::Type::rbx;
    }
    handler.freeRegister(tmp, type, compiled);
    
    lhs.get()->compile(type, compiled, env, handler, lblHandler, tmp);
    
    handler.freeRegister(tmp, type, compiled);
    rhs.get()->compile(type, compiled, env, handler, lblHandler, destination);
    handler.restoreRegister(tmp, type, compiled);
    
    compiled.push_back(make_unique<AsmCmp>( // -1000000 for AT&T intuition ...
            type,
            make_unique<AsmRegister>(destination),
            make_unique<AsmRegister>(tmp)
        )
    );
    
    compiled.push_back(getJump(resultTrue.get()));
    
    
    compiled.push_back(move(resultFalse));
    compiled.push_back(
        make_unique<AsmMov>(
            type,
            BoolConstant::getFalse(),
            make_unique<AsmRegister>(destination)
        )
    );
    compiled.push_back(make_unique<AsmJmp>(end.get()));
    compiled.push_back(move(resultTrue));
    compiled.push_back(
        make_unique<AsmMov>(
            type,
            BoolConstant::getTrue(),
            make_unique<AsmRegister>(destination)
        )
    );
    compiled.push_back(move(end));
    
    handler.restoreRegister(tmp, type, compiled);
}
