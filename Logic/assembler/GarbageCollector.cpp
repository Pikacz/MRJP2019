//
//  GarbageCollector.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 19/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "GarbageCollector.hpp"
#include "../ast/expressions/constants/BoolConstant.hpp"
#include "instructions/AsmMov.hpp"
#include "instructions/AsmCall.hpp"


using namespace std;


void GarbageCollector::wrap(
    string funcName,
    AsmRegister::Type source,
    AsmRegister::Type destination,
    bool isString,
    list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept{
    vector<AsmRegister::Type> regsToSave = handler.allUsedRegisters();
    
    
    for (size_t i = 0; i < regsToSave.size(); ++i) {
        if (regsToSave[i] != source && regsToSave[i] != destination) {
            handler.freeRegister(
                regsToSave[i], AssemblerValue::Size::bit64, compiled
            );
        }
    }
    
    if (source != AsmRegister::Type::rdi) {
        compiled.push_back(
            make_unique<AsmMov>(
                AssemblerValue::Size::bit64,
                make_unique<AsmRegister>(source),
                make_unique<AsmRegister>(AsmRegister::Type::rdi)
            )
        );
    }
    
    auto isStr = make_unique<BoolConstant>(isString, env, -1, -1);
    isStr->compile(AssemblerValue::Size::bit64, compiled, env, handler, lblHandler, AsmRegister::Type::rsi);
    
    compiled.push_back(
        make_unique<AsmCall>(
            AssemblerValue::Size::bit64, funcName
        )
    );
    
    if (destination != AsmRegister::Type::rax) {
        compiled.push_back(
            make_unique<AsmMov>(
                AssemblerValue::Size::bit64,
                make_unique<AsmRegister>(AsmRegister::Type::rax),
                make_unique<AsmRegister>(destination)
            )
        );
    }
    
    
    for (size_t ii = regsToSave.size(); ii > 0; --ii) {
        size_t i = ii - 1;
        if (regsToSave[i] != source && regsToSave[i] != destination) {
            handler.restoreRegister(
                regsToSave[i], AssemblerValue::Size::bit64, compiled
            );
        }
    }
}



void GarbageCollector::wrapCleanable(
    AsmRegister::Type source,
    AsmRegister::Type destination,
    bool isString,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept {
    wrap(
        "__Z16wrapDestructablePvx",
         source,
         destination,
         isString,
         compiled,
         env,
         handler,
         lblHandler
    );
}


// string constants etc
void GarbageCollector::wrapUncleanable(
    AsmRegister::Type source,
    AsmRegister::Type destination,
    bool isString,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept{
    wrap(
        "__Z18wrapUndestructablePvx",
         source,
         destination,
         isString,
         compiled,
         env,
         handler,
         lblHandler
    );
}


void GarbageCollector::getValue(
    AsmRegister::Type reg,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept {
    throw "TODO";
}


void GarbageCollector::counter(
    std::string funcName,
    AsmRegister::Type reg,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept {
    vector<AsmRegister::Type> regsToSave = handler.allUsedRegisters();
    
    
    for (size_t i = 0; i < regsToSave.size(); ++i) {
        handler.freeRegister(
            regsToSave[i], AssemblerValue::Size::bit64, compiled
        );
    }
    
    if (reg != AsmRegister::Type::rdi) {
        compiled.push_back(
            make_unique<AsmMov>(
                AssemblerValue::Size::bit64,
                make_unique<AsmRegister>(reg),
                make_unique<AsmRegister>(AsmRegister::Type::rdi)
            )
        );
    }
    
    compiled.push_back(
        make_unique<AsmCall>(
            AssemblerValue::Size::bit64, funcName
        )
    );
    
    
    for (size_t ii = regsToSave.size(); ii > 0; --ii) {
        size_t i = ii - 1;
        handler.restoreRegister(
            regsToSave[i], AssemblerValue::Size::bit64, compiled
        );
    }
}


void GarbageCollector::incCounter(
    AsmRegister::Type reg,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept {
    counter(
        "__Z10incCounterPv",
        reg, compiled, env, handler, lblHandler
    );
}


void GarbageCollector::decCounter(
    AsmRegister::Type reg,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler
) noexcept {
    counter(
        "__Z10decCounterPv",
        reg, compiled, env, handler, lblHandler
    );
}
