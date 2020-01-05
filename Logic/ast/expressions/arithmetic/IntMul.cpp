//
//  IntMul.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "IntMul.hpp"
#include "../../../assembler/instructions/AsmIMul.hpp"
#include "../../../assembler/instructions/AsmMov.hpp"

using namespace std;

bool IntMul::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<IntMul const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


AsmRegister::Type IntMul::lhsPosition(
    AsmRegister::Type destination, AsmRegistersHandler const & handler
) const noexcept {
    auto reg = handler.anyFreeNotEqual(destination);
    if (reg != nullopt) {
        return *reg;
    }
    if (destination != AsmRegister::Type::rbx) {
        return AsmRegister::Type::rbx;
    }
    return AsmRegister::Type::rax;
}


AsmRegister::Type IntMul::rhsPosition(
    AsmRegister::Type destination,
    AsmRegistersHandler const & handler,
    AsmRegister::Type lPos
) const noexcept {
    return destination;
}


void IntMul::calculate(
    list<unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler,
    AssemblerValue::Size type,
    AsmRegister::Type lPos,
    AsmRegister::Type rPos,
    AsmRegister::Type destination
) const noexcept {
    unique_ptr<const AsmInstruction> instr = make_unique<AsmIMul>(
        type, make_unique<AsmRegister>(lPos), make_unique<AsmRegister>(rPos)
    );
    compiled.push_back(move(instr));
    if (rPos != destination) {
        unique_ptr<const AsmInstruction> mov = make_unique<AsmMov>(
            type, make_unique<AsmRegister>(rPos), make_unique<AsmRegister>(rPos)
        );
    }
}
