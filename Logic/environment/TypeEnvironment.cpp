//
//  TypeEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "TypeEnvironment.hpp"

#include "function/Function.hpp"

#include <cassert>

using namespace std;


TypeEnvironment::TypeEnvironment(
    Environment const * global
) noexcept: parent(nullptr), global(global), EnvWithFunctions() {}


Variable const * TypeEnvironment::getVariableNamed(
    std::string name, bool expectingFunction, size_t line, size_t column
) const noexcept(false){
    throw "TODO";
}



void TypeEnvironment::declareVariable(
    std::string name, Type const * type, size_t line, size_t column
) noexcept(false) {
    throw "TODO";
}


Function const * TypeEnvironment::getFunctionNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    throw "TODO";
}


Function * TypeEnvironment::declareFunction(
    FunctionInitializer initializer, size_t line, size_t column
) noexcept(false) {
    throw "TODO";
}


Type const * TypeEnvironment::getTypeNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    return global->getTypeNamed(name, line, column);
}


AsmLabel const * TypeEnvironment::registerString(string str) const noexcept {
    return global->registerString(str);
}


void TypeEnvironment::setParent(TypeEnvironment const * parent) noexcept {
    assert(this->parent == nullptr);
    this->parent = parent;
}


FuncVariable const * TypeEnvironment::getConcatStrings() const noexcept {
    return global->getConcatStrings();
}

FuncVariable const * TypeEnvironment::getEqualStrings() const noexcept {
    return global->getEqualStrings();
}

FuncVariable const * TypeEnvironment::getNotEqualStrings() const noexcept {
    return global->getNotEqualStrings();
}
