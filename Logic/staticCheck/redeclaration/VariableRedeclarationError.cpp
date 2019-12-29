//
//  VariableRedeclarationError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "VariableRedeclarationError.hpp"

using namespace std;

VariableRedeclarationError::VariableRedeclarationError(
    size_t line, size_t column, string varName
) noexcept: varName(varName), StaticCheckError(line, column) {}


void VariableRedeclarationError::description(stringstream & ss) const noexcept {
    ss << "Variable named \"" << varName << "\" already exist.";
}
