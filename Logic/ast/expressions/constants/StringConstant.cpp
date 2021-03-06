//
//  StringConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "StringConstant.hpp"

#include "../../../assembler/instructions/AsmLea.hpp"
#include "../../../assembler/values/registers/AsmRegister.hpp"
#include "../../../assembler/GarbageCollector.hpp"

using namespace std;


StringConstant::StringConstant(
    string value, Environment const * env, size_t line, size_t column
) noexcept: location(env->registerString(value)), Constant<string>(value, env->getLatteString(), line, column) {}


void StringConstant::compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const noexcept {
    if (destination != AsmRegister::Type::rdi) {
        handler.freeRegister(
            AsmRegister::Type::rdi, AssemblerValue::Size::bit64, compiled
        );
    }
    
    
    compiled.push_back(
        make_unique<AsmLea>(
            type,
            make_unique<AsmData>(location),
            make_unique<AsmRegister>(AsmRegister::Type::rdi)
        )
    );
    GarbageCollector::wrapUncleanable(
        AsmRegister::Type::rdi, destination, true,
        compiled, env, handler, lblHandler
    );
    
    if (destination != AsmRegister::Type::rdi) {
        handler.restoreRegister(
            AsmRegister::Type::rdi, AssemblerValue::Size::bit64, compiled
        );
    }
}
