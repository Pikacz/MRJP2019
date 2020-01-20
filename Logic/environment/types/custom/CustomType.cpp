//
//  CustomType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CustomType.hpp"

#include "../../../staticCheck/types/CyclicDependency.hpp"

#include <cassert>

using namespace std;


CustomType::CustomType(
    string name
) noexcept: name(name), parentType(nullopt) {}


bool CustomType::isKindOf(Type const * type) const noexcept {
    if (auto nd = dynamic_cast<CustomType const *>(type)) {
        if (nd->name == name) {
            return true;
        }
    }
    if (parentType != nullopt) {
        return (*parentType)->isKindOf(type);
    }
    return false;
}


string CustomType::getName() const noexcept {
    return name;
}


size_t CustomType::pointerSize() const noexcept {
    return 8;
}


void CustomType::setParent(
    CustomType const * parent, size_t line, size_t column
) noexcept(false) {
    assert(parentType == nullopt);
    if (parent->isKindOf(this)) {
        throw CyclicDependency(line, column, this, parent);
    }
    parentType = parent;
}
