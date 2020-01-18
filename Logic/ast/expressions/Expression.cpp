//
//  Expression.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Expression.hpp"
#include <cassert>


Expression::Expression(
    Type const * type, size_t line, size_t column
) noexcept: type(type), AstNode(line, column) {}


Type const * Expression::getType() const noexcept {
    return type;
}

bool Expression::isKindOf(Type const * type) const noexcept {
    auto myType = getType();
    return myType->isKindOf(type);
}

bool Expression::isTerminating() const noexcept {
    return false;
}

void Expression::compileCall(
    AssemblerValue::Size size,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) const noexcept {
    assert(false);
}
