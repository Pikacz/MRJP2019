//
//  AllBuiltinTypes.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllBuiltinTypes.hpp"
#include "LatteBoolTests.hpp"
#include "LatteIntTests.hpp"
#include "LatteStringTests.hpp"
#include "LatteVoidTests.hpp"


using namespace std;

void runAllBuiltinTypes(string prefix) {
    LatteBoolTests t1("LatteBoolTests");
    t1.run(prefix);
    LatteIntTests t2("LatteIntTests");
    t2.run(prefix);
    LatteStringTests t3("LatteStringTests");
    t3.run(prefix);
    LatteVoidTests t4("LatteVoidTests");
    t4.run(prefix);
}
