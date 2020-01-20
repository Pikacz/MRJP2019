//
//  CyclicDependency.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "CyclicDependency.hpp"

using namespace std;

CyclicDependency::CyclicDependency(
    size_t line,
    size_t column,
    Type const * type,
    Type const * parentType
) noexcept
: type(type),
  parentType(parentType),
  StaticCheckError(line, column) {}


void CyclicDependency::description(stringstream & ss) const noexcept {
    ss << "Cyclic dependency. Type \"" << parentType->getName();
    ss << "\" deriveres from \"" << type->getName() << "\".";
}
