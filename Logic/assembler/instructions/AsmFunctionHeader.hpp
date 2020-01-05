//
//  AsmFunctionHeader.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmFunctionHeader_hpp
#define AsmFunctionHeader_hpp

#include "AsmInstruction.hpp"
#include <string>

class AsmFunctionHeader: public AsmInstruction {
public:
    AsmFunctionHeader(std::string funcName) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::string funcName;
};



#endif /* AsmFunctionHeader_hpp */
