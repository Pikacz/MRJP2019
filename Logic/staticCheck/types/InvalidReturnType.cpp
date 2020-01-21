//
//  InvalidReturnType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "InvalidReturnType.hpp"

using namespace std;


void InvalidReturnType::description(stringstream & ss) const noexcept {
    ss << "Expected return type \"" << expectedType;
    ss << "\" but got \"" << recievedType << "\" instead.";
}
