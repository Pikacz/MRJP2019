//
//  AsmCqto.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmCqto_hpp
#define AsmCqto_hpp

#include "AsmInstruction.hpp"


class AsmCqto final: public AsmInstruction {
public:
    using AsmInstruction::AsmInstruction;
    
    void write(std::stringstream & ss) const noexcept override;
};



#endif /* AsmCqto_hpp */
