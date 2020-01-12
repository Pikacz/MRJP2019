//
//  AsmJg.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJg.hpp"

using namespace std;

AsmJg::AsmJg(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJg::write(stringstream & ss) const noexcept {
    ss << "    jg      " << name << endl;
}
