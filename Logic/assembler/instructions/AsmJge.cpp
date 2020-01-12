//
//  AsmJge.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJge.hpp"

using namespace std;

AsmJge::AsmJge(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJge::write(stringstream & ss) const noexcept {
    ss << "    jge     " << name << endl;
}
