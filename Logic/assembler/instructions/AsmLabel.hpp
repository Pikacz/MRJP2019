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
class AsmJe;
class AsmJne;
class AsmJl;
class AsmJle;
class AsmJg;
class AsmJge;

class AsmLabel: public AsmInstruction {
public:
    AsmLabel(std::string name) noexcept;
    
    void write(std::stringstream & ss) const noexcept override;
    
    friend class AsmJmp;
    friend class AsmJe;
    friend class AsmJne;
    friend class AsmJl;
    friend class AsmJle;
    friend class AsmJg;
    friend class AsmJge;
private:
    const std::string name;
};


#endif /* AsmLabel_hpp */
