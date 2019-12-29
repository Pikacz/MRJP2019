//
//  AllAstTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllAstTests.hpp"

#include "expressions/AllExpressionsTests.hpp"

using namespace std;


void runAllAstTests(string prefix) noexcept {
    runAllExpressionsTests(prefix);
}
