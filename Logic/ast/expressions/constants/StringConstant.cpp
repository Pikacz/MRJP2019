//
//  StringConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "StringConstant.hpp"

using namespace std;


StringConstant::StringConstant(
    string value, Environment const * env, size_t line, size_t column
) noexcept: Constant<string>(value, env->getLatteString(), line, column) {}


void StringConstant::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    throw "not implemented";
}
