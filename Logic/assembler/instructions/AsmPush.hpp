//
//  AsmPush.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmPush_hpp
#define AsmPush_hpp

#include <stdio.h>
#include "Asm1Instruction.hpp"

class AsmPush final: public Asm1Instruction {
public:
    using Asm1Instruction::Asm1Instruction;
    
    std::string getName() const noexcept override;
};

#endif /* AsmPush_hpp */
