//
//  ExprNewArray.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprNewArray.hpp"

#include "../../staticCheck/types/InvalidType.hpp"


using namespace std;

ExprNewArray::ExprNewArray(
    Type const * type,
    Environment * env,
    unique_ptr<const Expression> _expr,
    size_t line, size_t column
) noexcept(false): elemType(type), expr(move(_expr)), Expression(env->getArrayOfType(type), line, column) {
    
    auto eType = this->expr.get()->getType();
    if (!expr->isKindOf(env->getLatteInt())) {
        throw InvalidType(
            this->expr.get()->getLine(),
            this->expr.get()->getColumn(),
            env->getLatteInt()->getName(),
            eType->getName()
        );
    }
}


bool ExprNewArray::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprNewArray const *>(node)) {
        return elemType->getName() == nd->elemType->getName() && expr->isEqualTo(nd->expr.get());
    }
    return false;
}


void ExprNewArray::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "new array expr is not implemented yet";
}
