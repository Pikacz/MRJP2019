//
//  AsmAdd.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmAdd_hpp
#define AsmAdd_hpp

#include "Asm2Instruction.hpp"


class AsmAdd final: public Asm2Instruction {
public:
    using Asm2Instruction::Asm2Instruction;
    
    std::string getName() const noexcept override;
};


#endif /* AsmAdd_hpp */
