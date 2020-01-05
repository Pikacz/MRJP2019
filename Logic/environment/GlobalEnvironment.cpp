//
//  GlobalEnvironment.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "GlobalEnvironment.hpp"

#include "../staticCheck/redeclaration/FunctionRedeclarationError.hpp"
#include "../staticCheck/main/MissingMain.hpp"

#include "function/Function.hpp"
#include "function/MainFunction.hpp"
#include "function/FunctionInitializer.hpp"

using namespace std;

static string mainName = "main";

// MARK: - constructor
GlobalEnvironment::GlobalEnvironment() noexcept: hasMain(false), Environment() {
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
    
    unique_ptr<Function> func;
    if (initializer.getName() != mainName) {
        func = make_unique<Function>(line, column, initializer, this);
    } else {
        func = make_unique<MainFunction>(line, column, initializer, this);
        hasMain = true;
    }
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


// MARK: - compilation
void GlobalEnvironment::compile(
    list<unique_ptr<const AsmInstruction>> & compiled
) const noexcept(false) {
    if (!hasMain) {
        throw MissingMain();
    }
    
    AsmLabelHandler lblHandler;
    
    for (auto const & type : types) {
        type.second.get()->compile(compiled);
    }
    
    
    for (auto const & func : functions) {
        func.second.get()->compile(compiled, lblHandler);
    }
}
