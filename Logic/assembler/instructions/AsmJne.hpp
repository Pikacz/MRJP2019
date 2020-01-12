//
//  AsmJne.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmJne_hpp
#define AsmJne_hpp

#include "AsmInstruction.hpp"
#include "AsmLabel.hpp"

#include <string>

class AsmJne: public AsmInstruction {
public:
    AsmJne(AsmLabel const * lbl) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::string name;
};

#endif /* AsmJne_hpp */
