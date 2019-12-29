//
//  AsmMov.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmMov_hpp
#define AsmMov_hpp



#include "Asm2Instruction.hpp"


class AsmMov final: public Asm2Instruction {
public:
    using Asm2Instruction::Asm2Instruction;
    
    std::string getName() const noexcept override;
};


#endif /* AsmMov_hpp */
