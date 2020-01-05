//
//  AsmMul.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmIMul_hpp
#define AsmIMul_hpp

#include "Asm2Instruction.hpp"


class AsmIMul final: public Asm2Instruction {
public:
    using Asm2Instruction::Asm2Instruction;
    
    std::string getName() const noexcept override;
};


#endif /* AsmIMul_hpp */
