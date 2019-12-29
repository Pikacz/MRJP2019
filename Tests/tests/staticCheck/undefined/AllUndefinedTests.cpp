//
//  AllUndefinedTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllUndefinedTests.hpp"

#include "NoSuchTypeErrorTests.hpp"
#include "NoSuchVariableErrorTests.hpp"

using namespace std;

void runAllUndefinedTests(string prefix) {
    NoSuchTypeErrorTests t1("NoSuchTypeErrorTests");
    t1.run(prefix);
    NoSuchVariableErrorTests t2("NoSuchVariableErrorTests");
    t2.run(prefix);
}
