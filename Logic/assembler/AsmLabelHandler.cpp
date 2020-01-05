//
//  AsmLabelHandler.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmLabelHandler.hpp"

#include <sstream>

using namespace std;

AsmLabelHandler::AsmLabelHandler() noexcept: counter(0) {}


unique_ptr<const AsmLabel> AsmLabelHandler::getNextLbl() noexcept {
    counter++;
    stringstream ss;
    ss << "latte_lbl_" << counter;
    return make_unique<AsmLabel>(ss.str());
}
