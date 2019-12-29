//
//  AsmIntConstant.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmIntConstant_hpp
#define AsmIntConstant_hpp

#include <stdio.h>
#include "AssemblerValue.hpp"

class AsmIntConstant final: public AssemblerValue {
public:
    AsmIntConstant(int val) noexcept;
    
    void write(
        std::stringstream &ss, AssemblerValue::Size size
    ) const noexcept override;
    
    bool isEqualTo(AssemblerValue const *val) const noexcept override;
private:
    const int val;
};

#endif /* AsmIntConstant_hpp */
