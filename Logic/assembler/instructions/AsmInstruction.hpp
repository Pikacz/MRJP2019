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
    AsmInstruction(AssemblerValue::Size type) noexcept;
    
    AssemblerValue::Size getType() const noexcept;
    
    virtual void write(std::stringstream & ss) const noexcept;
    
    virtual std::string getName() const noexcept = 0;
    
protected:
    void writeName(std::stringstream & ss) const noexcept;
private:
    void writeSuffix(std::stringstream & ss) const noexcept;
    
    const AssemblerValue::Size type;
};
#endif /* AsmInstruction_hpp */
