//
//  Type.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Type.hpp"


using namespace std;


Type::~Type() {
    
}

bool Type::isVoid() const noexcept {
    return false;
}


void Type::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    return;
}
