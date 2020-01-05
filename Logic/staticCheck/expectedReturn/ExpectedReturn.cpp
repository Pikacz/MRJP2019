//
//  ExpectedReturn.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExpectedReturn.hpp"

using namespace std;

ExpectedReturn::ExpectedReturn(
    size_t line, size_t column, string functionName, string typeName
) noexcept: functionName(functionName), typeName(typeName), StaticCheckError(line, column) {}


void ExpectedReturn::description(stringstream & ss) const noexcept {
    ss << "Function named \"" << functionName << "\" should return type \"";
    ss << typeName << "\".";
}
