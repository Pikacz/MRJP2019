//
//  AllComplicatedProgramsTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AllComplicatedProgramsTests.hpp"

#include "SimpleProgramsTests.hpp"

using namespace std;

void runAllComplicatedProgramsTests(string prefix) noexcept {
    SimpleProgramsTests t1("SimpleProgramsTests");
    t1.run(prefix);
}
