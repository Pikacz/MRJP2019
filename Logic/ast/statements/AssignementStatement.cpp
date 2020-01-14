//
//  AssignementStatement.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AssignementStatement.hpp"

#include "../../staticCheck/types/InvalidType.hpp"
#include "../../staticCheck/NotLValue.hpp"

using namespace std;

static unique_ptr<const LExpression> getLVal(
    unique_ptr<const Expression> var
) noexcept(false) {
    if (auto ptr = dynamic_cast<LExpression const *>(var.get())) {
        var.release();
        return unique_ptr<const LExpression>(ptr);
    }
    throw NotLValue(var.get());
}

AssignementStatement::AssignementStatement(
    size_t line,
    size_t column,
    unique_ptr<const Expression> var,
    unique_ptr<const Expression> expr
) noexcept(false): var(getLVal(move(var))), expr(move(expr)), Statement(line, column) {
    if (! this->expr.get()->isKindOf(this->var->getType())) {
        throw InvalidType(line, column, this->var->getType(), this->expr.get()->getType());
    }
}


bool AssignementStatement::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<AssignementStatement const *>(node)) {
        return var->isEqualTo(nd->var.get()) && expr.get()->isEqualTo(nd->expr.get());
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
