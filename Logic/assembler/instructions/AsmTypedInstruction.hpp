//
//  AsmTypedInstruction.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmTypedInstruction_hpp
#define AsmTypedInstruction_hpp

#include <stdio.h>

#include <string>
#include <sstream>

#include "AsmInstruction.hpp"
#include "../values/AssemblerValue.hpp"


class AsmTypedInstruction: public AsmInstruction {

public:
    AsmTypedInstruction(AssemblerValue::Size type) noexcept;
    
    AssemblerValue::Size getType() const noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    virtual std::string getName() const noexcept = 0;
    
protected:
    void writeName(std::stringstream & ss) const noexcept;
private:
    void writeSuffix(std::stringstream & ss) const noexcept;
    
    const AssemblerValue::Size type;
};



#endif /* AsmTypedInstruction_hpp */
