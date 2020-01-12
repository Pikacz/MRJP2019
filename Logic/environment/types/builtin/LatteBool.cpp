//
//  LatteBool.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteBool.hpp"

using namespace std;


bool LatteBool::isKindOf(Type const * type) const noexcept {
    return dynamic_cast<LatteBool const *>(type) != nullptr;
}

string LatteBool::getName() const noexcept {
    return "bool";
}

size_t LatteBool::pointerSize() const noexcept {
    return 8;
}
