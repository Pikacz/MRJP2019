//
//  AsmCqto.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AsmCqto.hpp"

using namespace std;


void AsmCqto::write(stringstream & ss) const noexcept {
    ss << "    cqto" << endl;
}
