//
//  ExprSubscript.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprSubscript.hpp"

#include "../../environment/types/ArrayType.hpp"
#include "../../staticCheck/types/CantBeSubscripted.hpp"
#include "../../staticCheck/types/InvalidType.hpp"


using namespace std;

static Type const * getElemT(Type const * type, size_t line, size_t column) noexcept(false) {
    auto result = dynamic_cast<ArrayType const *>(type);
    if (result == nullptr) {
        throw CantBeSubscripted(line, column, type->getName());
    }
    return result->getElemType();
}


ExprSubscript::ExprSubscript(
    size_t line,
    size_t column,
    Environment * env,
    std::unique_ptr<const Expression> _lhs,
    std::unique_ptr<const Expression> _expr
) noexcept(false):
    lhs(move(_lhs)),
    expr(move(_expr)),
    Expression(
        getElemT(_lhs->getType(), _lhs->getLine(), _lhs->getColumn()),
        line, column
    ) {
    
    auto eType = expr->getType();
    if (!eType->isKindOf(env->getLatteInt())) {
        throw InvalidType(
            this->expr.get()->getLine(),
            this->expr.get()->getColumn(),
            env->getLatteInt()->getName(),
            eType->getName()
        );
    }
}


bool ExprSubscript::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprSubscript const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            expr.get()->isEqualTo(nd->expr.get());
    }
    return false;
}

void ExprSubscript::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "array subscript is not implemented yet";
}
