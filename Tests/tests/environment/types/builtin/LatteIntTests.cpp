//
//  LatteIntTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteIntTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;


class IntTest final: public TestUnit {
public:
    IntTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        LatteInt i1, i2;
        LatteBool b1;
        LatteString s1;
        LatteVoid v1;
        
        assertTrue(i1.isKindOf(&i1));
        assertTrue(i1.isKindOf(&i2));
        assertTrue(i2.isKindOf(&i1));
        
        assertFalse(i1.isKindOf(&b1));
        assertFalse(i1.isKindOf(&s1));
        assertFalse(i1.isKindOf(&v1));
    }
};


vector<shared_ptr<TestUnit>> LatteIntTests::getTests() const noexcept {
    return {
        make_shared<IntTest>()
    };
}
