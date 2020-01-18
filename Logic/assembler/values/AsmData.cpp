//
//  AsmData.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 17/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmData.hpp"

using namespace std;


AsmData::AsmData(AsmLabel const * lbl) noexcept: lbl(lbl), rip(make_unique<AsmRegister>(AsmRegister::Type::rip)) {}


void AsmData::write(
    stringstream &ss, AssemblerValue::Size size
) const noexcept {
    ss << lbl->name << "(";
    rip->write(ss, size);
    ss << ")";
}


bool AsmData::isEqualTo(AssemblerValue const *val) const noexcept {
    if (auto rhs = dynamic_cast<AsmData const *>(val)) {
        return lbl->name == rhs->lbl->name;
    }
    return false;
}
