//
//  AsmCall.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmCall_hpp
#define AsmCall_hpp

#include "AsmTypedInstruction.hpp"

#include <string>

class AsmCall: public AsmTypedInstruction {
public:
    AsmCall(AssemblerValue::Size type, std::string funcName) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    std::string getName() const noexcept override;
private:
    const std::string funcName;
};


#endif /* AsmCall_hpp */
