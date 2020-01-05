//
//  AllTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllTests.hpp"
#include "staticCheck/AllStaticCheck.hpp"
#include "environment/AllEnvironment.hpp"
#include "ast/AllAstTests.hpp"
#include "assembler/AllAssemblerTests.hpp"
#include "compilation/AllCompilationTests.hpp"

using namespace std;

void runAllTests(string prefix) {
    runAllAssemblerTests(prefix);
    runAllAstTests(prefix);
    runAllStaticCheck(prefix);
    runAllEnvironment(prefix);
    
    runAllCompilationTests(prefix);
}
