//
//  LatteVoidTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteVoidTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;


class VoidTest final: public TestUnit {
public:
    VoidTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        LatteVoid v1, v2;
        LatteBool b1;
        LatteInt i1;
        LatteString s1;
        
        assertTrue(v1.isKindOf(&v1));
        assertTrue(v1.isKindOf(&v2));
        assertTrue(v2.isKindOf(&v1));
        
        assertFalse(v1.isKindOf(&b1));
        assertFalse(v1.isKindOf(&i1));
        assertFalse(v1.isKindOf(&s1));
    }
};


vector<shared_ptr<TestUnit>> LatteVoidTests::getTests() const noexcept {
    return {
        make_shared<VoidTest>()
    };
}
