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
        AsmRegister::Type::rdx,
        AsmRegister::Type::rdi,
        AsmRegister::Type::rsi,
        AsmRegister::Type::r8,
        AsmRegister::Type::r9,
        AsmRegister::Type::r10,
        AsmRegister::Type::r11,
        AsmRegister::Type::r12,
        AsmRegister::Type::r13,
        AsmRegister::Type::r14,
        AsmRegister::Type::r15
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
    auto search = registers.find(type);
    int count = search->second;

    if (count != 0) {
        unique_ptr<const AsmInstruction> push = make_unique<AsmPush>(
            size, make_unique<AsmRegister>(type)
        );
        compiled.push_back(move(push));
        
        unique_ptr<const AsmInstruction> push2 = make_unique<AsmPush>(
            size, make_unique<AsmRegister>(type)
        );
        compiled.push_back(move(push2));
    }
    registers[type] = count + 1;
}


void AsmRegistersHandler::restoreRegister(
    AsmRegister::Type type,
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled
) {
    auto search = registers.find(type);
    int count = search->second;
    
    if (count > 1) {
        unique_ptr<const AsmInstruction> pop = make_unique<AsmPop>(
            size, make_unique<AsmRegister>(type)
        );
        
        compiled.push_back(move(pop));
        
        unique_ptr<const AsmInstruction> pop2 = make_unique<AsmPop>(
            size, make_unique<AsmRegister>(type)
        );
        
        compiled.push_back(move(pop2));
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


vector<AsmRegister::Type> AsmRegistersHandler::allUsedRegisters() const noexcept {
    vector<AsmRegister::Type> result;
    for (auto it = registers.begin(); it != registers.end(); ++it) {
        if (it->second != 0) {
            result.push_back(it->first);
        }
    }
    return result;
}
