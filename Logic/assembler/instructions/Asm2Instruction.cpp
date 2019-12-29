//
//  Asm2Instruction.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Asm2Instruction.hpp"

using namespace std;

Asm2Instruction::Asm2Instruction(
    AssemblerValue::Size type,
    shared_ptr<const AssemblerValue> source,
    shared_ptr<const AssemblerValue> destination
) noexcept: source(source), destination(destination), AsmInstruction(type) {}


void Asm2Instruction::write(stringstream & ss) const noexcept {
    writeName(ss);
    source->write(ss, getType());
    ss << ",";
    destination->write(ss, getType());
    ss << endl;
}
