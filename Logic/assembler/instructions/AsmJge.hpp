//
//  AsmJge.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmJge_hpp
#define AsmJge_hpp

#include "AsmInstruction.hpp"
#include "AsmLabel.hpp"

#include <string>

class AsmJge: public AsmInstruction {
public:
    AsmJge(AsmLabel const * lbl) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::string name;
};

#endif /* AsmJge_hpp */
