//
//  AssignementStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AssignementStatement.hpp"

#include "../../staticCheck/types/InvalidType.hpp"

using namespace std;

AssignementStatement::AssignementStatement(
    size_t line,
    size_t column,
    LValue const * var,
    std::unique_ptr<const Expression> expr
) noexcept(false): var(var), expr(move(expr)), Statement(line, column) {
    if (! this->expr.get()->isKindOf(var->getType())) {
        throw InvalidType(line, column, var->getType(), this->expr.get()->getType());
    }
}


bool AssignementStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<AssignementStatement const *>(node)) {
        return var->isEqualTo(nd->var) && expr.get()->isEqualTo(nd->expr.get());
    }
    return false;
}

void AssignementStatement::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmLabelHandler & handler,
    AsmLabel const * exitLabel
) const noexcept {
    AsmRegistersHandler regHandler;
    expr.get()->compile(
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler,
        handler,
        AsmRegister::Type::rax
    );
    var->saveValueFrom(
        AsmRegister::Type::rax,
        AssemblerValue::Size::bit64,
        compiled,
        env,
        regHandler
    );
}
