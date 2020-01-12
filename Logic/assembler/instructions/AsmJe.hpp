//
//  AsmJe.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmJe_hpp
#define AsmJe_hpp

#include "AsmInstruction.hpp"
#include "AsmLabel.hpp"

#include <string>

class AsmJe: public AsmInstruction {
public:
    AsmJe(AsmLabel const * lbl) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::string name;
};

#endif /* AsmJe_hpp */
