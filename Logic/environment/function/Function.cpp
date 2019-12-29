//
//  Function.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 25/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Function.hpp"

#include "../FunctionEnvironment.hpp"

#include <cassert>

using namespace std;

Function::Function(
    FunctionInitializer initializer,
    Environment const * globalEnv
) noexcept:
    name(initializer.getName()),
    type(initializer.getType()),
    env(make_unique<FunctionEnvironment>(globalEnv)),
    isCompleted(false) {
}


void Function::completeWith(
    vector<unique_ptr<const Statement>> statements
) noexcept {
    assert(!isCompleted);
    isCompleted = true;
    this->statements = move(statements);
}


Environment * Function::getEnvironment() const noexcept {
    assert(!isCompleted);
    return env.get();
}
