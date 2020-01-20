//
//  LatteString.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteString.hpp"

using namespace std;


bool LatteString::isKindOf(Type const * type) const noexcept {
    return dynamic_cast<LatteString const *>(type) != nullptr;
}

string LatteString::getName() const noexcept {
    return "string";
}

size_t LatteString::pointerSize() const noexcept {
    return 8;
}

bool LatteString::isPointer() const noexcept {
    return true;
}
