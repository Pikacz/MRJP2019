//
//  ParserError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ParserError.hpp"

using namespace std;

ParserError::ParserError(string msg) noexcept: msg(msg) {}

string ParserError::what() const noexcept {
    return msg;
}
