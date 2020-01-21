//
//  TypeRedeclaration.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "TypeRedeclaration.hpp"

using namespace std;

TypeRedeclaration::TypeRedeclaration(
    size_t line, size_t column, string typeName
) noexcept: typeName(typeName), StaticCheckError(line, column) {}


void TypeRedeclaration::description(stringstream & ss) const noexcept {
    ss << "type named \"" << typeName << "\" already exist.";
}
