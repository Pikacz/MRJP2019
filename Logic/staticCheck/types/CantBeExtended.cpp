//
//  CantBeExtended.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CantBeExtended.hpp"

using namespace std;

CantBeExtended::CantBeExtended(
    size_t line,
    size_t column,
    string type
) noexcept
: type(type),
  StaticCheckError(line, column) {}


void CantBeExtended::description(stringstream & ss) const noexcept {
    ss << "Type \"" << type << " can't be extended.";
}
