//
//  Type.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Type.hpp"

#include "../../staticCheck/types/InvalidMember.hpp"
#include "../variables/Variable.hpp"

using namespace std;


Type::~Type() {
    
}

bool Type::isVoid() const noexcept {
    return false;
}


Variable const * Type::getMemberNamed(std::string name, size_t line, size_t column) const noexcept(false) {
    throw InvalidMember(line, column, this->getName(), name);
}


void Type::compile(
    std::list<std::unique_ptr<const AsmInstruction>> & compiled
) const noexcept {
    return;
}


bool Type::isPointer() const noexcept {
    return false;
}


bool Type::isArray() const noexcept {
    return false;
}


bool Type::isObject() const noexcept {
    return false;
}
