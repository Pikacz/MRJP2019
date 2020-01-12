//
//  IntConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "IntConstant.hpp"

#include "../../../assembler/values/AsmIntConstant.hpp"
#include "../../../assembler/values/registers/AsmRegister.hpp"
#include "../../../assembler/instructions/AsmMov.hpp"


using namespace std;


IntConstant::IntConstant(
    int value, Environment const * env, size_t line, size_t column
) noexcept: Constant<int>(value, env->getLatteInt(), line, column) {}


void IntConstant::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    unique_ptr<const AsmInstruction> mov = make_unique<AsmMov>(
        type,
        make_unique<AsmIntConstant>(getValue()),
        make_unique<AsmRegister>(destination)
    );
    compiled.push_back(move(mov));
}
