//
//  FuncVariable.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 14/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "FuncVariable.hpp"

#include "../../assembler/instructions/AsmCall.hpp"

using namespace std;

FuncVariable::FuncVariable(
    Function const * func, Environment const * env
) noexcept: func(func), Variable(func->getType(), env) {
    
}


void FuncVariable::compileCall(
    AssemblerValue::Size size,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) const noexcept {
    compiled.push_back(make_unique<AsmCall>(size, func->getCompiledName()));
    
}

Function const * FuncVariable::getFunction() const noexcept {
    return func;
}
