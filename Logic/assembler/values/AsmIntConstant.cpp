//
//  AsmIntConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmIntConstant.hpp"


AsmIntConstant::AsmIntConstant(int val) noexcept: val(val) {}


void AsmIntConstant::write(
    std::stringstream &ss, AssemblerValue::Size size
) const noexcept {
    ss << "$" << val;
}


bool AsmIntConstant::isEqualTo(AssemblerValue const * val) const noexcept {
    if (auto rhs = dynamic_cast<AsmIntConstant const *>(val)) {
        return this->val == rhs->val;
    }
    return false;
}
