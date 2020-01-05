//
//  AsmIDiv.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmIDiv_hpp
#define AsmIDiv_hpp

#include "Asm1Instruction.hpp"

class AsmIDiv final: public Asm1Instruction {
public:
    using Asm1Instruction::Asm1Instruction;
    
    std::string getName() const noexcept override;
};

#endif /* AsmIDiv_hpp */
