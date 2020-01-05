//
//  AsmLabel.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmLabel_hpp
#define AsmLabel_hpp

#include "AsmInstruction.hpp"
#include <string>

class AsmJmp;

class AsmLabel: public AsmInstruction {
public:
    AsmLabel(std::string name) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    friend class AsmJmp;
    
private:
    const std::string name;
};


#endif /* AsmLabel_hpp */
