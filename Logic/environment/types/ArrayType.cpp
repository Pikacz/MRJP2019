//
//  ArrayType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ArrayType.hpp"

#include <sstream>

using namespace std;


ArrayType::ArrayType(Type const * type) noexcept: type(type), Type() {}

bool ArrayType::isKindOf(Type const * type) const noexcept {
    if (auto nd = dynamic_cast<ArrayType const *>(type)) {
        return this->type->isKindOf(nd->type);
    }
    return false;
}

string ArrayType::getName() const noexcept {
    stringstream ss;
    ss << type->getName() << "[]";
    return ss.str();
}

size_t ArrayType::pointerSize() const noexcept {
    return 8;
}

bool ArrayType::isPointer() const noexcept {
    return true;
}
