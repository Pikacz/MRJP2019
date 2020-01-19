//
//  GarbageCollector.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 19/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef GarbageCollector_hpp
#define GarbageCollector_hpp

#include <stdio.h>

#include <memory>
#include <list>

#include "values/AssemblerValue.hpp"
#include "instructions/AsmInstruction.hpp"
#include "AsmLabelHandler.hpp"
#include "AsmRegistersHandler.hpp"
#include "../environment/Environment.hpp"

class GarbageCollector {
    // objects, dynamic strings
    static void wrapCleanable(
        AsmRegister::Type reg,
        bool isString,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    );
    
    // string constants etc
    static void wrapUncleanable(
        AsmRegister::Type reg,
        bool isString,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    );
    
    static std::unique_ptr<const AssemblerValue> getValue(
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    );
    
    static void incCounter(
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    );
    
    static void decCounter(
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    );
    
};

#endif /* GarbageCollector_hpp */
