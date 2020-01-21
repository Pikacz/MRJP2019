//
//  TypeNotAnObject.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "TypeNotAnObject.hpp"

using namespace std;

TypeNotAnObject::TypeNotAnObject(
    size_t line,
    size_t column,
    string type
) noexcept
: type(type),
  StaticCheckError(line, column) {}


void TypeNotAnObject::description(stringstream & ss) const noexcept {
    ss << "Type \"" << type << " is not an object.";
}

