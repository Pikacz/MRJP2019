//
//  AllComplicatedProgramsTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AllComplicatedProgramsTests.hpp"

#include "SimpleProgramsTests.hpp"
#include "MimUWTests.hpp"
#include "ObjectTests.hpp"

using namespace std;

void runAllComplicatedProgramsTests(string prefix) noexcept {
    SimpleProgramsTests t1("SimpleProgramsTests");
    t1.run(prefix);
    MimUWTests t2("MimUWTests");
    t2.run(prefix);
    ObjectTests t3("ObjectTests");
    t3.run(prefix);
}
