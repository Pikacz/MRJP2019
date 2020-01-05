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

using namespace std;

Function::Function(
    size_t line, size_t column,
    FunctionInitializer initializer,
    Environment const * globalEnv
) noexcept:
    line(line), column(column),
    name(initializer.getName()),
    type(initializer.getType()),
    env(make_unique<FunctionEnvironment>(globalEnv, initializer)),
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
}


FunctionEnvironment * Function::getEnvironment() const noexcept {
    assert(!isCompleted);
    return env.get();
}


void Function::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    AsmLabelHandler & handler
) const noexcept {
    unique_ptr<const AsmInstruction> header = make_unique<AsmFunctionHeader>(name);
    compiled.push_back(move(header));
    env.get()->compileVariables(compiled);
    
    unique_ptr<const AsmLabel> exitLbl = handler.getNextLbl();
    
    for (size_t i = 0; i < statements.size(); ++i) {
        statements[i].get()->compile(compiled, env.get(), handler, exitLbl.get());
    }
    compiled.push_back(move(exitLbl));
    env.get()->cleanVariables(compiled);
    
    unique_ptr<const AsmInstruction> ret = make_unique<AsmRet>(
        AssemblerValue::Size::bit64
    );
    compiled.push_back(move(ret));
}
