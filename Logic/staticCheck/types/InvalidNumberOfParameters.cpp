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
    std::string recievedType,
    size_t expectedParams,
    size_t recievedParameters
) noexcept
: recievedType(recievedType), expectedParams(expectedParams), recievedParameters(recievedParameters),
  StaticCheckError(line, column) {}


void InvalidNumberOfParameters::description(stringstream & ss) const noexcept {
    ss << "Call on type " << recievedType << "requires ";
    ss << expectedParams << " parameters, but got ";
    ss << recievedParameters << " instead.";
}
