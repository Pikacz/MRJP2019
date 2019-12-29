//
//  TestCase.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "TestCase.hpp"
#include <iostream>


using namespace std;


TestCase::TestCase(string name) noexcept: name(name) {}


string TestCase::getName() const noexcept {
    return name;
}


void TestCase::run(std::string prefix) const noexcept {
    cout << prefix << "Running " << getName() << ":" << endl;
    auto tests = getTests();
    for (auto test : tests) {
        cout << prefix << "  " << test->getName() << ": ";
        cout.flush();
        test->run();
        cout << "OK" << endl;
    }
}
