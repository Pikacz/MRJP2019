//
//  InvalidNumberOfParameters.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "InvalidNumberOfParameters.hpp"

using namespace std;

InvalidNumberOfParameters::InvalidNumberOfParameters(
    size_t line,
    size_t column,
    FunctionType const * recievedType,
    size_t recievedParameters
) noexcept
: recievedType(recievedType), recievedParameters(recievedParameters),
  StaticCheckError(line, column) {}


void InvalidNumberOfParameters::description(stringstream & ss) const noexcept {
    ss << "Call on type " << recievedType->getName() << "requires ";
    ss << recievedType->getParameters().size() << " parameters, but got ";
    ss << recievedParameters << " instead.";
}
