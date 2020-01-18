//
//  AllCompilationTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AllCompilationTests.hpp"
#include "returnValue/AllReturnValueTests.hpp"
#include "complicatedPrograms/AllComplicatedProgramsTests.hpp"

using namespace std;

void runAllCompilationTests(string prefix) noexcept {
    runAllReturnValueTests(prefix);
    runAllComplicatedProgramsTests(prefix);
}
