//
//  AsmRet.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmRet_hpp
#define AsmRet_hpp

#include <stdio.h>
#include "AsmTypedInstruction.hpp"

class AsmRet final: public AsmTypedInstruction {
public:
    using AsmTypedInstruction::AsmTypedInstruction;
    
    std::string getName() const noexcept override;
};

#endif /* AsmRet_hpp */
