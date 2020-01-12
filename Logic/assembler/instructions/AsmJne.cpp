//
//  AsmJne.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJne.hpp"

using namespace std;

AsmJne::AsmJne(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJne::write(stringstream & ss) const noexcept {
    ss << "    jne     " << name << endl;
}
