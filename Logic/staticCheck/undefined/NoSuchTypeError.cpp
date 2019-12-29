//
//  NoSuchTypeError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "NoSuchTypeError.hpp"

using namespace std;

NoSuchTypeError::NoSuchTypeError(
    size_t line, size_t column, string typeName
) noexcept: typeName(typeName), StaticCheckError(line, column) {}


void NoSuchTypeError::description(stringstream & ss) const noexcept {
    ss << "Type named \"" << typeName << "\" does not exist.";
}
