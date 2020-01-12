//
//  LatteInt.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteInt.hpp"

using namespace std;


bool LatteInt::isKindOf(Type const * type) const noexcept {
    return dynamic_cast<LatteInt const *>(type) != nullptr;
}

string LatteInt::getName() const noexcept {
    return "int";
}

size_t LatteInt::pointerSize() const noexcept {
    return 8;
}

