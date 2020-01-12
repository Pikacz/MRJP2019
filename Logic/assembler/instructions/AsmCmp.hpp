//
//  AsmCmp.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmCmp_hpp
#define AsmCmp_hpp

#include "Asm2Instruction.hpp"


class AsmCmp final: public Asm2Instruction {
public:
    using Asm2Instruction::Asm2Instruction;
    
    std::string getName() const noexcept override;
};

#endif /* AsmCmp_hpp */
