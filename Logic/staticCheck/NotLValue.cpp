//
//  NotLValue.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "NotLValue.hpp"

using namespace std;

NotLValue::NotLValue(
    Expression const * expr
) noexcept: StaticCheckError(expr->getLine(), expr->getColumn()) {}


void NotLValue::description(stringstream & ss) const noexcept {
    ss << "Expected lValue." << endl;
}
