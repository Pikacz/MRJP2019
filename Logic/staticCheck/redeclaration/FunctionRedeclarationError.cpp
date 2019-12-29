//
//  FunctionRedeclarationError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "FunctionRedeclarationError.hpp"


using namespace std;

FunctionRedeclarationError::FunctionRedeclarationError(
    size_t line, size_t column, string funcName
) noexcept: funcName(funcName), StaticCheckError(line, column) {}


void FunctionRedeclarationError::description(stringstream & ss) const noexcept {
    ss << "function named \"" << funcName << "\" already exist.";
}
