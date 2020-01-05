//
//  MainInvalidType.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "MainInvalidType.hpp"

using namespace std;

MainInvalidType::MainInvalidType(size_t line, size_t column) noexcept:
    StaticCheckError(line, column) {}


void MainInvalidType::description(stringstream & ss) const noexcept {
    ss << "Main function should return int and have no parameters";
}
