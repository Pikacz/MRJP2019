//
//  AsmTypedInstruction.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmTypedInstruction.hpp"

using namespace std;

AsmTypedInstruction::AsmTypedInstruction(AssemblerValue::Size type) noexcept: type(type) {}


AssemblerValue::Size AsmTypedInstruction::getType() const noexcept {
    return type;
}


void AsmTypedInstruction::writeSuffix(stringstream & ss) const noexcept {
    switch (type) {
        case AssemblerValue::Size::bit8:
            ss << "b";
            break;
        case AssemblerValue::Size::bit16:
            ss << "w";
            break;
        case AssemblerValue::Size::bit32:
            ss << "l";
            break;
        case AssemblerValue::Size::bit64:
            ss << "q";
            break;
    }
}

void AsmTypedInstruction::writeName(stringstream & ss) const noexcept {
    string name = getName();
    size_t spaces = 7 - name.length();
    ss << "    " << name;
    writeSuffix(ss);
    for (size_t i = 0; i < spaces; ++i) {
        ss << " ";
    }
}

void AsmTypedInstruction::write(std::stringstream & ss) const noexcept {
    writeName(ss);
    ss << endl;
}
