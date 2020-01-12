//
//  AsmJle.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmJle_hpp
#define AsmJle_hpp

#include "AsmInstruction.hpp"
#include "AsmLabel.hpp"

#include <string>

class AsmJle: public AsmInstruction {
public:
    AsmJle(AsmLabel const * lbl) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::string name;
};

#endif /* AsmJle_hpp */
