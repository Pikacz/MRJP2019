//
//  AllStaticCheck.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AllStaticCheck.hpp"

#include "redeclaration/AllRedeclarationTests.hpp"
#include "undefined/AllUndefinedTests.hpp"

using namespace std;


void runAllStaticCheck(string prefix) {
    runAllRedeclarationTests(prefix);
    runAllUndefinedTests(prefix);
}
