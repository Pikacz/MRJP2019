//
//  LValue.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "LValue.hpp"
#include "../../assembler/instructions/AsmMov.hpp"
#include "../../assembler/values/registers/AsmRegister.hpp"


using namespace std;


LValue::~LValue() {}


void LValue::saveValueFrom(
    AsmRegister::Type source,
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler
) const noexcept {
    handler.freeRegister(source, size, compiled);
    auto mem = getAddress(size, compiled, env, handler);
    handler.restoreRegister(source, size, compiled);
    
    unique_ptr<const AsmInstruction> mov = make_unique<AsmMov>(
        size, make_unique<AsmRegister>(source), move(mem)
    );
    compiled.push_back(move(mov));
}


void LValue::loadValueInto(
    AsmRegister::Type destination,
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler
) const noexcept {
    auto mem = getAddress(size, compiled, env, handler);
    unique_ptr<const AsmInstruction> mov = make_unique<AsmMov>(
        size, move(mem), make_unique<AsmRegister>(destination)
    );
    compiled.push_back(move(mov));
}
