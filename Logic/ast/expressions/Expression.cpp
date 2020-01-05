//
//  Expression.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Expression.hpp"


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



