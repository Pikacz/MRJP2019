//
//  AsmJg.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmJg_hpp
#define AsmJg_hpp

#include "AsmInstruction.hpp"
#include "AsmLabel.hpp"

#include <string>

class AsmJg: public AsmInstruction {
public:
    AsmJg(AsmLabel const * lbl) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    
private:
    const std::string name;
};

#endif /* AsmJg_hpp */
