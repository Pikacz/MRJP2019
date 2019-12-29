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


using namespace std;


Variable const * Environment::getVariableNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    throw NoSuchVariableError(line, column, name);
}


// MARK:- types
Type const * Environment::getTypeNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    throw NoSuchTypeError(line, column, name);
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
    return "bool";
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
