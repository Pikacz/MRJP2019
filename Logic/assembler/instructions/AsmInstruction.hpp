//
//  AsmInstruction.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmInstruction_hpp
#define AsmInstruction_hpp

#include <string>
#include <sstream>

#include "../values/AssemblerValue.hpp"


class AsmInstruction {

public:
    virtual ~AsmInstruction();
    
    
    virtual void write(std::stringstream & ss) const noexcept = 0;
};
#endif /* AsmInstruction_hpp */
