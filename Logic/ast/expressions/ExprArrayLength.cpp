//
//  ExprArrayLength.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprArrayLength.hpp"

#include "../../environment/types/ArrayType.hpp"
#include "../../staticCheck/types/CantBeSubscripted.hpp"


using namespace std;

static void checkIsArray(Type const * type, size_t line, size_t column) noexcept(false) {
    auto result = dynamic_cast<ArrayType const *>(type);
    if (result == nullptr) {
        throw CantBeSubscripted(line, column, type->getName());
    }
}



ExprArrayLength::ExprArrayLength(
    size_t line,
    size_t column,
    Environment * env,
    std::unique_ptr<const Expression> _expr
) noexcept(false):
    expr(move(_expr)),
    Expression(env->getLatteInt(), line, column) {
        
    checkIsArray(expr->getType(), line, column);
}


bool ExprArrayLength::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<ExprArrayLength const *>(node)) {
        return expr->isEqualTo(nd->expr.get());
    }
    return false;
}


void ExprArrayLength::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "array.length is not implemented yet";
}
