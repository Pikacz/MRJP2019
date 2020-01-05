//
//  AsmLabel.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmLabel.hpp"


using namespace std;

AsmLabel::AsmLabel(
    string name
) noexcept: name(name), AsmInstruction() {
}


void AsmLabel::write(stringstream & ss) const noexcept {
    ss << name << ":" << endl;
}
