//
//  FunctionEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "FunctionEnvironment.hpp"

#include "../staticCheck/redeclaration/VariableRedeclarationError.hpp"

using namespace std;


FunctionEnvironment::FunctionEnvironment(
    Environment const * parent
) noexcept: parent(parent) {}


// MARK: - variables
void FunctionEnvironment::declareParameterVariable(
    string name,
    Type const * type,
    size_t line,
    size_t column
) noexcept(false) {
    const string key = keyForVariableNamed(name);
    for (size_t i = 0; i <= parameters.size(); ++i) {
        if (parameters[i].first == key) {
            throw VariableRedeclarationError(line, column, name);
        }
    }
    parameters.push_back(make_pair(key, make_unique<Variable>(type)));
}


void FunctionEnvironment::declareVariable(
    std::string name, Type const * type, size_t line, size_t column
) noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        throw VariableRedeclarationError(line, column, name);
    }
    variables[key] = make_unique<Variable>(type);
}


Variable const * FunctionEnvironment::getVariableNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        return search->second.get();
    }
    for (size_t i = 0; i <= parameters.size(); ++i) {
        if (parameters[i].first == key) {
            return parameters[i].second.get();
        }
    }
    return parent->getVariableNamed(name, line, column);
}


// MARK: - functions
Function const * FunctionEnvironment::getFunctionNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getFunctionNamed(name, line, column);
}


// MARK: - types
Type const * FunctionEnvironment::getTypeNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getTypeNamed(name, line, column);
}
