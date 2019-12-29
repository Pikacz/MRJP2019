//
//  AsmInstruction.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmInstruction.hpp"

using namespace std;

AsmInstruction::AsmInstruction(AssemblerValue::Size type) noexcept: type(type) {}



AssemblerValue::Size AsmInstruction::getType() const noexcept {
    return type;
}


void AsmInstruction::writeSuffix(stringstream & ss) const noexcept {
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

void AsmInstruction::writeName(stringstream & ss) const noexcept {
    string name = getName();
    size_t spaces = 7 - name.length();
    ss << "    " << name;
    writeSuffix(ss);
    for (size_t i = 0; i < spaces; ++i) {
        ss << " ";
    }
}

void AsmInstruction::write(std::stringstream & ss) const noexcept {
    writeName(ss);
    ss << endl;
}
