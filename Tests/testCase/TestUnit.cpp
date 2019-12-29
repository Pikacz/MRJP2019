//
//  TestUnit.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "TestUnit.hpp"

using namespace std;

TestUnit::TestUnit(string name) noexcept: name(name) {}


void TestUnit::assertTrue(bool expr) {
    if (!expr) {
        throw 1;
    }
}


void TestUnit::assertFalse(bool expr) {
    if (expr) {
        throw 1;
    }
}


string TestUnit::getName() const noexcept {
    return name;
}
