//
//  NotExpr.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "NotExpr.hpp"

#include "../constants/BoolConstant.hpp"
#include "../../../staticCheck/types/InvalidType.hpp"
#include "../../../assembler/instructions/AsmJmp.hpp"
#include "../../../assembler/instructions/AsmCmp.hpp"
#include "../../../assembler/instructions/AsmJe.hpp"
#include "../../../assembler/instructions/AsmMov.hpp"

using namespace std;

NotExpr::NotExpr(
    Environment const * env,
    size_t line,
    size_t column,
    unique_ptr<const Expression> _expr
) noexcept(false): Expr1Arg(env->getLatteBool(), line, column, move(_expr)) {
    auto eType = this->expr.get()->getType();
    if (!eType->isKindOf(env->getLatteBool())) {
        throw InvalidType(
            this->expr.get()->getLine(),
            this->expr.get()->getColumn(),
            env->getLatteBool(),
            eType
        );
    }
}


bool NotExpr::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<NotExpr const *>(node)) {
        return expr.get()->isEqualTo(nd->expr.get());
    }
    return false;
}


void NotExpr::compile(
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
    
    
    expr.get()->compile(type, compiled, env, handler, lblHandler, destination);
    compiled.push_back(make_unique<AsmCmp>(
        type,
        BoolConstant::getFalse(),
        make_unique<AsmRegister>(destination))
    );
    compiled.push_back(
        make_unique<AsmJe>(resultTrue.get())
    );
    
    // wynik
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
}
