//
//  AsmJl.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmJl.hpp"

using namespace std;

AsmJl::AsmJl(
    AsmLabel const * lbl
) noexcept: name(lbl->name), AsmInstruction() {
}


void AsmJl::write(stringstream & ss) const noexcept {
    ss << "    jl      " << name << endl;
}
