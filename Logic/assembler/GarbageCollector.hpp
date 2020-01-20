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
public:
    // objects, dynamic strings, source will be overriden
    static void wrapCleanable(
        AsmRegister::Type source,
        AsmRegister::Type destination,
        bool isString,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
    
    // string constants, source will be overriden
    static void wrapUncleanable(
        AsmRegister::Type source,
        AsmRegister::Type destination,
        bool isString,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
    
    static void getValue(
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
    
    
    static void incCounter(
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
    
    static void decCounter(
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
    
private:
    static void wrap(
        std::string funcName,
        AsmRegister::Type source,
        AsmRegister::Type destination,
        bool isString,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
    
    static void counter(
        std::string funcName,
        AsmRegister::Type reg,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) noexcept;
};

#endif /* GarbageCollector_hpp */
