//
//  AsmJmp.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJmp.hpp"

using namespace std;

AsmJmp::AsmJmp(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJmp::write(stringstream & ss) const noexcept {
    ss << "    jmp     " << name << endl;
}
