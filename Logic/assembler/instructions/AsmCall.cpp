//
//  AsmCall.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmCall.hpp"

using namespace std;

AsmCall::AsmCall(
    AssemblerValue::Size type, string funcName
) noexcept: funcName(funcName), AsmTypedInstruction(type) {
}


void AsmCall::write(stringstream & ss) const noexcept {
    writeName(ss);
    ss << funcName;
    ss << endl;
}

string AsmCall::getName() const noexcept {
    return "call";
}

