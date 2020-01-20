//
//  Function.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 25/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Function.hpp"

#include "../FunctionEnvironment.hpp"

#include "../../staticCheck/expectedReturn/ExpectedReturn.hpp"

#include "../../assembler/instructions/AsmFunctionHeader.hpp"
#include "../../assembler/instructions/AsmRet.hpp"



#include <cassert>
#include <sstream>

using namespace std;

Function::Function(
    size_t line, size_t column,
    FunctionInitializer initializer,
    Environment const * globalEnv,
    bool isMain
) noexcept:
    line(line), column(column),
    name(initializer.getName()),
    type(initializer.getType()),
    env(make_unique<FunctionEnvironment>(globalEnv, initializer, isMain)),
    isCompleted(false) {
}


void Function::completeWith(
    vector<unique_ptr<const Statement>> statements
) noexcept(false) {
    assert(!isCompleted);
    isCompleted = true;
    
    bool finishes = type->getReturnType()->isVoid();
    
    for (size_t i = 0; i < statements.size(); ++i) {
        if (statements[i].get()->isTerminatingWith(type->getReturnType())) {
            finishes = true;
        }
    }
    
    if (!finishes) {
        throw ExpectedReturn(
            line, column, name, type->getReturnType()->getName()
        );
    }
    
    this->statements = move(statements);
    
    size_t fake_vars = 0;
    for (auto & s: this->statements) {
        fake_vars = max(fake_vars, s->fakeVariablesCount());
    }
    env->declareFakeVariables(fake_vars);
}


FunctionEnvironment * Function::getEnvironment() const noexcept {
    assert(!isCompleted);
    return env.get();
}


void Function::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmLabelHandler & handler
) const noexcept {
    string name;
    unique_ptr<const AsmInstruction> header = make_unique<AsmFunctionHeader>(
        getCompiledName()
    );
    compiled.push_back(move(header));
    AsmRegistersHandler regHandler;
    
    env.get()->compileVariables(compiled, regHandler);
    
    unique_ptr<const AsmLabel> exitLbl = handler.getNextLbl();
    
    for (size_t i = 0; i < statements.size(); ++i) {
        statements[i].get()->compile(compiled, env.get(), handler, exitLbl.get());
    }
    compiled.push_back(move(exitLbl));
    // rax jest ustwione i cenne
    regHandler.freeRegister(AsmRegister::Type::rax, AssemblerValue::Size::bit64, compiled);
    // jesli ktos bedzie chciał użyc rax to musi go wrzucić wpier na stos, a później odtworzyć
    env.get()->cleanVariables(compiled, regHandler, handler);
    
    unique_ptr<const AsmInstruction> ret = make_unique<AsmRet>(
        AssemblerValue::Size::bit64
    );
    compiled.push_back(move(ret));
}




FunctionType const * Function::getType() const noexcept {
    return type.get();
}

string Function::getName() const noexcept {
    return name;
}

bool Function::isTerminating() const noexcept {
    return false;
}


string Function::getCompiledName() const noexcept {
    stringstream ss;
    ss << "_latte_func_" << name;
    return ss.str();
}
