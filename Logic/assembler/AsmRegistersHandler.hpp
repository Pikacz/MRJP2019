//
//  AsmRegistersHandler.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmRegistersHandler_hpp
#define AsmRegistersHandler_hpp

#include <list>
#include <memory>
#include <map>
#include <optional>
#include <vector>
 

#include "instructions/AsmInstruction.hpp"
#include "values/registers/AsmRegister.hpp"

class AsmRegistersHandler final {
public:
    AsmRegistersHandler() noexcept;
    
    void freeRegister(
        AsmRegister::Type type,
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    );
    
    void restoreRegister(
        AsmRegister::Type type,
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    );
    
    std::optional<AsmRegister::Type> anyFreeNotEqual(
        AsmRegister::Type type
    ) const noexcept;
    
    std::vector<AsmRegister::Type> allUsedRegisters() const noexcept;
private:
    std::map<AsmRegister::Type, int> registers;
    std::list<AsmRegister::Type> pushedRegisters;
};

#endif /* AsmRegistersHandler_hpp */
