//
//  AllConstantsTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllConstantsTests.hpp"
#include "BoolConstantTests.hpp"
#include "IntConstantTests.hpp"
#include "StringConstantTests.hpp"

using namespace std;

void runAllConstantsTests(string prefix) noexcept {
    IntConstantTests t1("IntConstantTests");
    t1.run(prefix);
    BoolConstantTests t2("BoolConstantTests");
    t2.run(prefix);
    StringConstantTests t3("StringConstantTests");
    t3.run(prefix);
}
