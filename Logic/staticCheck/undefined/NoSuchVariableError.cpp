//
//  NoSuchVariableError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "NoSuchVariableError.hpp"

using namespace std;

NoSuchVariableError::NoSuchVariableError(
    size_t line, size_t column, string varName
) noexcept: varName(varName), StaticCheckError(line, column) {}


void NoSuchVariableError::description(stringstream & ss) const noexcept {
    ss << "Variable named \"" << varName << "\" does not exist.";
}

