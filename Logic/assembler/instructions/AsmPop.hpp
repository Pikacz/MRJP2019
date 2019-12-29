//
//  AsmPop.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmPop_hpp
#define AsmPop_hpp

#include <stdio.h>
#include "Asm1Instruction.hpp"

class AsmPop final: public Asm1Instruction {
public:
    using Asm1Instruction::Asm1Instruction;
    
    std::string getName() const noexcept override;
};


#endif /* AsmPop_hpp */
