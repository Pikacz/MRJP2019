//
//  Environment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Environment.hpp"

#include "../staticCheck/undefined/NoSuchFunctionError.hpp"
#include "../staticCheck/undefined/NoSuchTypeError.hpp"
#include "../staticCheck/undefined/NoSuchVariableError.hpp"

#include "function/Function.hpp"
#include "function/FunctionInitializer.hpp"
#include <cassert>


using namespace std;


Environment::Environment() noexcept {
}

Variable const * Environment::getVariableNamed(
    string name, bool expectingFunction, size_t line, size_t column
) const noexcept(false) {
    throw NoSuchVariableError(line, column, name);
}

Variable const * Environment::getNextFakeVariable() const noexcept {
    assert(false);
}

void Environment::releaseFakeVariable(
    Variable const * var,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) const noexcept {
    assert(false);
}


// MARK:- types
Type const * Environment::getTypeNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    throw NoSuchTypeError(line, column, name);
}

ArrayType const * Environment::getArrayOfType(Type const * type) noexcept {
    arrays.push_back(make_unique<ArrayType>(type));
    return arrays.end()->get();
}

LatteBool const * Environment::getLatteBool() const noexcept {
    return dynamic_cast<LatteBool const *>(
        getTypeNamed(boolName(), 0, 0)
    );
}

LatteInt const * Environment::getLatteInt() const noexcept {
    return dynamic_cast<LatteInt const *>(
        getTypeNamed(intName(), 0, 0)
    );
}

LatteString const * Environment::getLatteString() const noexcept {
    return dynamic_cast<LatteString const *>(
        getTypeNamed(stringName(), 0, 0)
    );
}

LatteVoid const * Environment::getLatteVoid() const noexcept {
    return dynamic_cast<LatteVoid const *>(
        getTypeNamed(voidName(), 0, 0)
    );
}



// MARK:- functions
Function const * Environment::getFunctionNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    throw NoSuchFunctionError(line, column, name);
}

void Environment::markFuncCall(size_t parameters_count) noexcept {
    
}


FuncVariable const * Environment::getConcatStrings() const noexcept {
    assert(false);
}


// MARK:- keys
string Environment::keyForVariableNamed(string name) noexcept {
    return name;
}


string Environment::keyForFunctionNamed(string name) noexcept {
    return name;
}


string Environment::keyForTypeNamed(string name) noexcept {
    return name;
}


string Environment::boolName() noexcept {
    return "boolean";
}

string Environment::intName() noexcept {
    return "int";
}

string Environment::stringName() noexcept {
    return "string";
}

string Environment::voidName() noexcept {
    return "void";
}
