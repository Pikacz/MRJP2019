//
//  ExpectedFunctionType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExpectedFunctionType.hpp"

using namespace std;

ExpectedFunctionType::ExpectedFunctionType(
    size_t line,
    size_t column,
    string recievedType
) noexcept
: recievedType(recievedType),
  StaticCheckError(line, column) {}


void ExpectedFunctionType::description(stringstream & ss) const noexcept {
    ss << "Call is not defined for type " << recievedType << ".";
}
