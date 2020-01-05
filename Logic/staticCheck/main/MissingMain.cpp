//
//  MissingMain.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "MissingMain.hpp"

MissingMain::MissingMain() noexcept: StaticCheckError(0, 0) {}


void MissingMain::description(std::stringstream & ss) const noexcept {
    ss << "Main function is not defined.";
}
