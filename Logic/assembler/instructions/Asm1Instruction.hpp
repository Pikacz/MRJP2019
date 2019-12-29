//
//  Asm1Instruction.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Asm1Instruction_hpp
#define Asm1Instruction_hpp

#include <stdio.h>
#include "AsmInstruction.hpp"
#include <string>
#include <memory>

class Asm1Instruction: public AsmInstruction {
public:
    Asm1Instruction(
        AssemblerValue::Size type,
        std::shared_ptr<const AssemblerValue> arg
    ) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::shared_ptr<const AssemblerValue> arg;
};



#endif /* Asm1Instruction_hpp */
