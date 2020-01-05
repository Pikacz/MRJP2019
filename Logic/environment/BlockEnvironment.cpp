//
//  BlockEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "BlockEnvironment.hpp"

#include "../staticCheck/redeclaration/VariableRedeclarationError.hpp"

#include "function/Function.hpp"
#include "function/FunctionInitializer.hpp"

using namespace std;


BlockEnvironment::BlockEnvironment(
    Environment const * parent
) noexcept: parent(parent), Environment() {}


// MARK: - variables
void BlockEnvironment::declareVariable(
    std::string name, Type const * type, size_t line, size_t column
) noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        throw VariableRedeclarationError(line, column, name);
    }
    variables[key] = make_unique<Variable>(type);
}


Variable const * BlockEnvironment::getVariableNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        return search->second.get();
    }
    return parent->getVariableNamed(name, line, column);
}


// MARK: - functions
Function const * BlockEnvironment::getFunctionNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getFunctionNamed(name, line, column);
}


// MARK: - types
Type const * BlockEnvironment::getTypeNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    return parent->getTypeNamed(name, line, column);
}


// MARK: - compilation
void BlockEnvironment::compileVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    
}


void BlockEnvironment::cleanVariables(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    
}
