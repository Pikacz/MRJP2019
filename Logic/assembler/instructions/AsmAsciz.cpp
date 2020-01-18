//
//  AsmAsciz.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 17/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmAsciz.hpp"


using namespace std;

AsmAsciz::AsmAsciz(
    string val
) noexcept: val(val), AsmInstruction() {
}


void AsmAsciz::write(stringstream & ss) const noexcept {
    ss << "    .asciz  \"" << val << "\"" << endl;
}
