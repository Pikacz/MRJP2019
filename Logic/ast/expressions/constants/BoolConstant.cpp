//
//  BoolConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "BoolConstant.hpp"

using namespace std;


BoolConstant::BoolConstant(
    bool value, Environment const * env, size_t line, size_t column
) noexcept: Constant<bool>(value, env->getLatteBool(), line, column) {}


void BoolConstant::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmRegister::Type destination
) const noexcept {
    throw "not implemented";
}
