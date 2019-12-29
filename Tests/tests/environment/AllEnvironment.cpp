//
//  AllEnvironment.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllEnvironment.hpp"
#include "EnvironmentTests.hpp"
#include "types/AllTypesTests.hpp"

using namespace std;


void runAllEnvironment(string prefix) {
    runAllTypesTests(prefix);
    EnvironmentTests t1("EnvironmentTests");
    t1.run(prefix);
}
