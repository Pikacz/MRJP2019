//
//  AsmFunctionHeader.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmFunctionHeader.hpp"

using namespace std;

AsmFunctionHeader::AsmFunctionHeader(
    std::string funcName
) noexcept: funcName(funcName), AsmInstruction() {
    
}


void AsmFunctionHeader::write(stringstream & ss) const noexcept {
    stringstream ss2;
    ss2 << funcName;
    string name = ss2.str();
    
    ss << "    .globl  " << name << endl;
    ss << name << ":" << endl;
    
}
