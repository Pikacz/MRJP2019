//
//  IntMod.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "IntMod.hpp"
#include "../../../assembler/instructions/AsmCqto.hpp"
#include "../../../assembler/instructions/AsmIDiv.hpp"
#include "../../../assembler/instructions/AsmMov.hpp"
#include <cassert>

using namespace std;

bool IntMod::isEqualTo(AstNode const * node) const noexcept {
    if (auto nd = dynamic_cast<IntMod const *>(node)) {
        return lhs.get()->isEqualTo(nd->lhs.get()) &&
            rhs.get()->isEqualTo(nd->rhs.get());
    }
    return false;
}


AsmRegister::Type IntMod::lhsPosition(
    AsmRegister::Type destination, AsmRegistersHandler const & handler
) const noexcept {
    return AsmRegister::Type::rax;
}


AsmRegister::Type IntMod::rhsPosition(
    AsmRegister::Type destination,
    AsmRegistersHandler const & handler,
    AsmRegister::Type lPos
) const noexcept {
    return AsmRegister::Type::rbx;
}


void IntMod::calculate(
    list<unique_ptr<const AsmInstruction>> & compiled,
    AsmRegistersHandler & handler,
    AssemblerValue::Size type,
    AsmRegister::Type lPos,
    AsmRegister::Type rPos,
    AsmRegister::Type destination
) const noexcept {
    
    if (AsmRegister::Type::rax != destination && AsmRegister::Type::rax != lPos && AsmRegister::Type::rax != rPos) {
        handler.freeRegister(AsmRegister::Type::rax, type, compiled);
    }
    
    if (AsmRegister::Type::rdx != destination && AsmRegister::Type::rdx != lPos && AsmRegister::Type::rdx != rPos) {
        handler.freeRegister(AsmRegister::Type::rdx, type, compiled);
    }
    
    if (rPos == AsmRegister::Type::rdx || rPos == AsmRegister::Type::rax) {
        assert(false);
    }
    
    unique_ptr<const AsmInstruction> instr1 = make_unique<AsmCqto>();
    compiled.push_back(move(instr1));
    
    unique_ptr<const AsmInstruction> instr2 = make_unique<AsmIDiv>(
        type, make_unique<AsmRegister>(rPos)
    );
    compiled.push_back(move(instr2));
    if (destination != AsmRegister::Type::rdx) {
        unique_ptr<const AsmInstruction> mov = make_unique<AsmMov>(
            type, make_unique<AsmRegister>(AsmRegister::Type::rdx), make_unique<AsmRegister>(destination)
        );
        compiled.push_back(move(mov));
    }
    
    
    if (AsmRegister::Type::rdx != destination && AsmRegister::Type::rdx != lPos && AsmRegister::Type::rdx != rPos) {
        handler.restoreRegister(AsmRegister::Type::rdx, type, compiled);
    }
    if (AsmRegister::Type::rax != destination && AsmRegister::Type::rax != lPos && AsmRegister::Type::rax != rPos) {
        handler.restoreRegister(AsmRegister::Type::rax, type, compiled);
    }
}
