//
//  AsmJe.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJe.hpp"

using namespace std;

AsmJe::AsmJe(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJe::write(stringstream & ss) const noexcept {
    ss << "    je      " << name << endl;
}
