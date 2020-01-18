//
//  AsmData.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 17/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmData_hpp
#define AsmData_hpp

#include "AssemblerValue.hpp"

#include "../instructions/AsmLabel.hpp"
#include "registers/AsmRegister.hpp"

#include <memory>

class AsmData final: public AssemblerValue {
public:
    AsmData(AsmLabel const * lbl) noexcept;
    
    void write(
        std::stringstream &ss, AssemblerValue::Size size
    ) const noexcept override;
    
    bool isEqualTo(AssemblerValue const *val) const noexcept override;
private:
    const AsmLabel * const lbl;
    
    const std::unique_ptr<const AsmRegister> rip;
};

#endif /* AsmData_hpp */
