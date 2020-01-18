//
//  AsmLea.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 17/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmLea_hpp
#define AsmLea_hpp

#include "Asm2Instruction.hpp"


class AsmLea final: public Asm2Instruction {
public:
    using Asm2Instruction::Asm2Instruction;
    
    std::string getName() const noexcept override;
};

#endif /* AsmLea_hpp */
