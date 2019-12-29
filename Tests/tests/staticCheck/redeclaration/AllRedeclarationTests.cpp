//
//  AllRedeclarationTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllRedeclarationTests.hpp"

#include "VariableRedeclarationTests.hpp"

using namespace std;

void runAllRedeclarationTests(string prefix) {
    VariableRedeclarationTests t1("VariableRedeclarationTests");
    t1.run(prefix);
}
