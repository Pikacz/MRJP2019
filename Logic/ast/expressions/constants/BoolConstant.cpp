//
//  BoolConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "BoolConstant.hpp"


#include "../../../assembler/values/registers/AsmRegister.hpp"
#include "../../../assembler/instructions/AsmMov.hpp"

using namespace std;


BoolConstant::BoolConstant(
    bool value, Environment const * env, size_t line, size_t column
) noexcept: Constant<bool>(value, env->getLatteBool(), line, column) {}


void BoolConstant::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    unique_ptr<const AsmInstruction> mov = make_unique<AsmMov>(
        type,
        getValue() ? getTrue() : getFalse(),
        make_unique<AsmRegister>(destination)
    );
    compiled.push_back(move(mov));
}


std::unique_ptr<AsmIntConstant> BoolConstant::getTrue() noexcept {
    return make_unique<AsmIntConstant>(1);
}

std::unique_ptr<AsmIntConstant> BoolConstant::getFalse() noexcept {
    return make_unique<AsmIntConstant>(0);
}
