//
//  AsmIntConstantTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmIntConstantTests.hpp"
#include "../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

#include <sstream>

using namespace std;

class AsmIntRepresentationTest final: public TestUnit {
public:
    AsmIntRepresentationTest(): TestUnit("Representation test") {}
    
    void run() noexcept override {
        stringstream ss;
        AsmIntConstant i1(1), i2(-1), i3(0);
        
        i1.write(ss, AssemblerValue::Size::bit32);
        assertTrue(ss.str() == "$1");
        ss.str("");
        
        i1.write(ss, AssemblerValue::Size::bit64);
        assertTrue(ss.str() == "$1");
        ss.str("");
        
        i2.write(ss, AssemblerValue::Size::bit32);
        assertTrue(ss.str() == "$-1");
        ss.str("");
        
        i2.write(ss, AssemblerValue::Size::bit64);
        assertTrue(ss.str() == "$-1");
        ss.str("");
        
        i3.write(ss, AssemblerValue::Size::bit32);
        assertTrue(ss.str() == "$0");
        ss.str("");
        
        i3.write(ss, AssemblerValue::Size::bit64);
        assertTrue(ss.str() == "$0");
        ss.str("");
    }
};


class AsmIntCompareTest: public TestUnit {
public:
    AsmIntCompareTest(): TestUnit("Compare test") {}
    
    void run() noexcept override {
//        AsmRegister r1(AsmRegister::Type::eax);
//        AsmRegister r2(AsmRegister::Type::ebx);
//        
//        AsmIntConstant i1(12), i2(12), i3(-1);
//        
//        AsmMemory m1(1, &r1, &r2, AsmMemory::ScaleT::one);
//        
//        assertTrue(i1.isEqualTo(&i2));
//        assertTrue(i1.isEqualTo(&i1));
//        assertTrue(i2.isEqualTo(&i1));
//        
//        assertFalse(i1.isEqualTo(&i3));
//        assertFalse(i3.isEqualTo(&i1));
//        assertFalse(i1.isEqualTo(&r1));
//        assertFalse(i1.isEqualTo(&m1));
    }
};

vector<shared_ptr<TestUnit>> AsmIntConstantTests::getTests() const noexcept {
    
    return {
        make_shared<AsmIntRepresentationTest>(),
        make_shared<AsmIntCompareTest>()
    };
}
