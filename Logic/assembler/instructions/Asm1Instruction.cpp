//
//  Asm1Instruction.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Asm1Instruction.hpp"

using namespace std;

Asm1Instruction::Asm1Instruction(
    AssemblerValue::Size type,
    shared_ptr<const AssemblerValue> arg
) noexcept: arg(arg), AsmInstruction(type) {}


void Asm1Instruction::write(stringstream & ss) const noexcept {
    writeName(ss);
    arg->write(ss, getType());
    ss << endl;
}
