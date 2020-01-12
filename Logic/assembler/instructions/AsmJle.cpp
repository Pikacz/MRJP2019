//
//  AsmJle.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJle.hpp"

using namespace std;

AsmJle::AsmJle(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJle::write(stringstream & ss) const noexcept {
    ss << "    jle     " << name << endl;
}
