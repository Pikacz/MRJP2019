//
//  Variable.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "Variable.hpp"
#include "../types/Type.hpp"
#include "../Environment.hpp"

#include <cassert>

using namespace std;

Variable::Variable(
    Type const * type, Environment const * env
):
type(type), location(nullopt) {
}


unique_ptr<const AssemblerValue> Variable::getAddress(
    AssemblerValue::Size size,
    list<unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler
) const noexcept {
    assert(location != nullopt);
    return make_unique<AsmMemory>(*location->get());
}


Type const * Variable::getType() const noexcept {
    return type;
}


bool Variable::isEqualTo(Variable const * node) const noexcept {
    if (auto nd = dynamic_cast<Variable const *>(node)) {
        if (type->isKindOf(nd->type)) {
            if (location == nullopt && nd->location == nullopt) {
                return true;
            } else if (location != nullopt && nd->location != nullopt) {
                return (*location)->isEqualTo(nd->location->get());
            }
        }
    }
    
    return false;
}


void Variable::setMemory(unique_ptr<const AsmMemory> memory) noexcept {
    assert(location == nullopt);
    location = move(memory);
}


bool Variable::isMemberVar() const noexcept {
    return false;
}
