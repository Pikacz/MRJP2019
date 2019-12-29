//
//  LatteBoolTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteBoolTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;


class BoolTest final: public TestUnit {
public:
    BoolTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        LatteBool b1, b2;
        LatteInt i1;
        LatteString s1;
        LatteVoid v1;
        
        assertTrue(b1.isKindOf(&b1));
        assertTrue(b1.isKindOf(&b2));
        assertTrue(b2.isKindOf(&b1));
        
        assertFalse(b1.isKindOf(&i1));
        assertFalse(b1.isKindOf(&s1));
        assertFalse(b1.isKindOf(&v1));
    }
};


vector<shared_ptr<TestUnit>> LatteBoolTests::getTests() const noexcept {
    return {
        make_shared<BoolTest>()
    };
}
