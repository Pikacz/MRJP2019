//
//  NoSuchFunctionError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "NoSuchFunctionError.hpp"

using namespace std;

NoSuchFunctionError::NoSuchFunctionError(
    size_t line, size_t column, string funcName
) noexcept: funcName(funcName), StaticCheckError(line, column) {}


void NoSuchFunctionError::description(stringstream & ss) const noexcept {
    ss << "Function named \"" << funcName << "\" does not exist.";
}
