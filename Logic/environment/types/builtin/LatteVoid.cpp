//
//  LatteVoid.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteVoid.hpp"

#include <cassert>

using namespace std;


bool LatteVoid::isKindOf(Type const * type) const noexcept {
    return dynamic_cast<LatteVoid const *>(type) != nullptr;
}

string LatteVoid::getName() const noexcept {
    return "void";
}

size_t LatteVoid::pointerSize() const noexcept {
    assert(false);
}
