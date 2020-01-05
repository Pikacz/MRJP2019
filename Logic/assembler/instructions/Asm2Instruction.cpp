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
    unique_ptr<const AssemblerValue> source,
    unique_ptr<const AssemblerValue> destination
) noexcept: source(move(source)), destination(move(destination)), AsmTypedInstruction(type) {}


void Asm2Instruction::write(stringstream & ss) const noexcept {
    writeName(ss);
    source.get()->write(ss, getType());
    ss << ", ";
    destination.get()->write(ss, getType());
    ss << endl;
}
