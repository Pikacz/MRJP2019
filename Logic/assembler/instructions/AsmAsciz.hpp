//
//  AsmAsciz.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 17/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmAsciz_hpp
#define AsmAsciz_hpp

#include "AsmInstruction.hpp"
#include <string>

class AsmAsciz final: public AsmInstruction {
public:
    AsmAsciz(std::string val) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
private:
    const std::string val;
};

#endif /* AsmAsciz_hpp */
