//
//  LateStringTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "LatteStringTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;


class StringTest final: public TestUnit {
public:
    StringTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        LatteString s1, s2;
        LatteBool b1;
        LatteInt i1;
        LatteVoid v1;
        
        assertTrue(s1.isKindOf(&s1));
        assertTrue(s1.isKindOf(&s2));
        assertTrue(s2.isKindOf(&s1));
        
        assertFalse(s1.isKindOf(&b1));
        assertFalse(s1.isKindOf(&i1));
        assertFalse(s1.isKindOf(&v1));
    }
};


vector<shared_ptr<TestUnit>> LatteStringTests::getTests() const noexcept {
    return {
        make_shared<StringTest>()
    };
}
