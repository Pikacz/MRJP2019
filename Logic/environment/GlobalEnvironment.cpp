//
//  GlobalEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "GlobalEnvironment.hpp"

#include "../staticCheck/redeclaration/FunctionRedeclarationError.hpp"

using namespace std;


// MARK: - constructor
GlobalEnvironment::GlobalEnvironment() noexcept {
    string key;
    key = keyForTypeNamed(boolName());
    types[key] = make_unique<LatteBool>();
    key = keyForTypeNamed(intName());
    types[key] = make_unique<LatteInt>();
    key = keyForTypeNamed(stringName());
    types[key] = make_unique<LatteString>();
    key = keyForTypeNamed(voidName());
    types[key] = make_unique<LatteVoid>();
}


// MARK: - functions
Function const * GlobalEnvironment::getFunctionNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForFunctionNamed(name);
    auto search = functions.find(key);
    if (search != functions.end()) {
        return search->second.get();
    }
    return Environment::getFunctionNamed(name, line, column);
}


Function * GlobalEnvironment::declareFunction(
    FunctionInitializer initializer, size_t line, size_t column
) noexcept(false) {
    string key = keyForFunctionNamed(initializer.getName());
    auto search = functions.find(key);
    if (search != functions.end()) {
        throw FunctionRedeclarationError(
            line, column, initializer.getName()
        );
    }
    unique_ptr<Function> func = make_unique<Function>(initializer, this);
    Function * result = func.get();
    functions[key] = move(func);
    return result;
}


// MARK: - types
Type const * GlobalEnvironment::getTypeNamed(
    std::string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForTypeNamed(name);
    auto search = types.find(key);
    if (search != types.end()) {
        return search->second.get();
    }
    
    return Environment::getTypeNamed(name, line, column);
}
