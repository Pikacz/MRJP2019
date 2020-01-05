//
//  InvalidType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "InvalidType.hpp"

using namespace std;

InvalidType::InvalidType(
    size_t line,
    size_t column,
    Type const * expectedType,
    Type const * recievedType
) noexcept
: expectedType(expectedType),
  recievedType(recievedType),
  StaticCheckError(line, column) {}


void InvalidType::description(stringstream & ss) const noexcept {
    ss << "Expected type \"" << expectedType->getName();
    ss << "\" but got \"" << recievedType->getName() << "\" instead.";
}
