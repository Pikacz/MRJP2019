//
//  AsmRegistersHandler.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmRegistersHandler.hpp"
#include "instructions/AsmPush.hpp"
#include "instructions/AsmPop.hpp"

using namespace std;

AsmRegistersHandler::AsmRegistersHandler() noexcept {
    
    auto regs = {
        AsmRegister::Type::rax,
        AsmRegister::Type::rbx,
        AsmRegister::Type::rcx,
        AsmRegister::Type::rdx
    };
    
    for (auto r : regs) {
        registers[r] = 0;
    }
}


void AsmRegistersHandler::freeRegister(
    AsmRegister::Type type,
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled
) {
    int count = registers[type];
    if (count != 0) {
        unique_ptr<const AsmInstruction> push = make_unique<AsmPush>(
            size, make_unique<AsmRegister>(type)
        );
        compiled.push_back(move(push));
    }
    registers[type] = count + 1;
}


void AsmRegistersHandler::restoreRegister(
    AsmRegister::Type type,
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled
) {
    int count = registers[type];
    
    if (count > 1) {
        unique_ptr<const AsmInstruction> pop = make_unique<AsmPop>(
            size, make_unique<AsmRegister>(type)
        );
        
        compiled.push_back(move(pop));
    }
    
    registers[type] = count - 1;
    
}


optional<AsmRegister::Type> AsmRegistersHandler::anyFreeNotEqual(
    AsmRegister::Type type
) const noexcept {
    for (auto it = registers.begin(); it != registers.end(); ++it) {
        if (it->first != type && it->second == 0) {
            return it->first;
        }
    }
    return nullopt;
}
