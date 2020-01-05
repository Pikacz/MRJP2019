//
//  Asm2Instruction.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Asm2Instruction_hpp
#define Asm2Instruction_hpp

#include <stdio.h>
#include "AsmTypedInstruction.hpp"
#include <string>
#include <memory>

class Asm2Instruction: public AsmTypedInstruction {
public:
    Asm2Instruction(
        AssemblerValue::Size type,
        std::unique_ptr<const AssemblerValue> source,
        std::unique_ptr<const AssemblerValue> destination
    ) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::unique_ptr<const AssemblerValue> source;
    const std::unique_ptr<const AssemblerValue> destination;
};


#endif /* Asm2Instruction_hpp */
