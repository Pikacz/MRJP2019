//
//  InvalidMember.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "InvalidMember.hpp"


using namespace std;

InvalidMember::InvalidMember(
    size_t line,
    size_t column,
    string type,
    string member
) noexcept
: type(type),
  member(member),
  StaticCheckError(line, column) {}


void InvalidMember::description(stringstream & ss) const noexcept {
    ss << "Type \"" << type << " don't have member named \"" << member << "\".";
}

