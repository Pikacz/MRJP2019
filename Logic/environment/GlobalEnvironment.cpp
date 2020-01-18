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
#include "function/builtin/PrintInt.hpp"
#include "function/builtin/LattePrintString.hpp"
#include "function/builtin/LatteError.hpp"
#include "function/builtin/ReadInt.hpp"
#include "function/builtin/ReadString.hpp"
#include "variables/FuncVariable.hpp"
#include "../assembler/instructions/AsmAsciz.hpp"


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
    
    
    unique_ptr<Function> func;
    unique_ptr<FuncVariable> funcVar;
    func = make_unique<PrintInt>(this);
    funcVar = make_unique<FuncVariable>(func.get(), this);
    key = keyForVariableNamed(func.get()->getName());
    variables[key] = move(funcVar);
    key = keyForFunctionNamed(func.get()->getName());
    functions[key] = move(func);
    
    func = make_unique<LattePrintString>(this);
    funcVar = make_unique<FuncVariable>(func.get(), this);
    key = keyForVariableNamed(func.get()->getName());
    variables[key] = move(funcVar);
    key = keyForFunctionNamed(func.get()->getName());
    functions[key] = move(func);
    
    func = make_unique<LatteError>(this);
    funcVar = make_unique<FuncVariable>(func.get(), this);
    key = keyForVariableNamed(func.get()->getName());
    variables[key] = move(funcVar);
    key = keyForFunctionNamed(func.get()->getName());
    functions[key] = move(func);
    
    func = make_unique<ReadInt>(this);
    funcVar = make_unique<FuncVariable>(func.get(), this);
    key = keyForVariableNamed(func.get()->getName());
    variables[key] = move(funcVar);
    key = keyForFunctionNamed(func.get()->getName());
    functions[key] = move(func);
    
    func = make_unique<ReadString>(this);
    funcVar = make_unique<FuncVariable>(func.get(), this);
    key = keyForVariableNamed(func.get()->getName());
    variables[key] = move(funcVar);
    key = keyForFunctionNamed(func.get()->getName());
    functions[key] = move(func);
    
    auto concatString = make_unique<ConcatString>(this);
    funcVar = make_unique<FuncVariable>(concatString.get(), this);
    _concatString = funcVar.get();
    key = keyForVariableNamed(concatString.get()->getName());
    variables[key] = move(funcVar);
    key = keyForFunctionNamed(concatString.get()->getName());
    functions[key] = move(concatString);
}


// MARK: - variables
Variable const * GlobalEnvironment::getVariableNamed(
    string name, size_t line, size_t column
) const noexcept(false) {
    const string key = keyForVariableNamed(name);
    auto search = variables.find(key);
    if (search != variables.end()) {
        return search->second.get();
    }
    return Environment::getVariableNamed(name, line, column);
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
    string varKey = keyForVariableNamed(result->getName());
    variables[varKey] = make_unique<FuncVariable>(result, this);
    functions[key] = move(func);
    
    return result;
}


FuncVariable const * GlobalEnvironment::getConcatStrings() const noexcept {
    return _concatString;
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

// MARK: - string
AsmLabel const * GlobalEnvironment::registerString(string str) const noexcept {
    
    size_t number = strings.size() + 1;
    stringstream ss;
    ss << "L_.str." << number;
    string lbl_name = ss.str();
    auto lbl = make_unique<AsmLabel>(lbl_name);
    auto result = lbl.get();
    strings[lbl_name] = str;
    stringLabels.push_back(move(lbl));
    return result;
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
    
    string lbl_name;
    for (size_t i = 0; i < stringLabels.size(); ++i) {
        lbl_name = stringLabels[i]->name;
        compiled.push_back(make_unique<AsmLabel>(lbl_name));
        compiled.push_back(make_unique<AsmAsciz>(strings[lbl_name]));
    }
}
