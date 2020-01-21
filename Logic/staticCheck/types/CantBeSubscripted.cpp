//
//  CantBeSubscripted.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CantBeSubscripted.hpp"


using namespace std;

CantBeSubscripted::CantBeSubscripted(
    size_t line,
    size_t column,
    string type
) noexcept
: type(type),
  StaticCheckError(line, column) {}


void CantBeSubscripted::description(stringstream & ss) const noexcept {
    ss << "Type \"" << type << " can't be subscripted.";
}

