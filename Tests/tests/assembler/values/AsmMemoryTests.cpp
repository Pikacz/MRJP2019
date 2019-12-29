//
//  AsmMemoryTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmMemoryTests.hpp"
#include "../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

#include <sstream>

using namespace std;

class AsmMemRepresentationTest final: public TestUnit {
public:
    AsmMemRepresentationTest(): TestUnit("Representation test") {}
    
    void run() noexcept override {
//        stringstream ss;
//        AsmRegister eax(AsmRegister::Type::eax);
//        AsmRegister ebx(AsmRegister::Type::ebx);
//
//        AsmMemory m1(4, &eax, &ebx, AsmMemory::ScaleT::one);
//        AsmMemory m2(-4, &eax, &ebx, AsmMemory::ScaleT::one);
//        AsmMemory m3(-4, nullptr, &ebx, AsmMemory::ScaleT::one);
//        AsmMemory m4(-4, &eax, nullptr, AsmMemory::ScaleT::one);
//        AsmMemory m5(-4, nullptr, nullptr, AsmMemory::ScaleT::one);
//        AsmMemory m6(-4, &eax, &ebx, AsmMemory::ScaleT::four);
//
//        m1.write(ss);
//        assertTrue(ss.str() == "4(%eax,%ebx,1)");
//        ss.str("");
//
//        m2.write(ss);
//        auto s = ss.str();
//        assertTrue(ss.str() == "-4(%eax,%ebx,1)");
//        ss.str("");
//
//        m3.write(ss);
//        assertTrue(ss.str() == "-4(,%ebx,1)");
//        ss.str("");
//
//        m4.write(ss);
//        assertTrue(ss.str() == "-4(%eax)");
//        ss.str("");
//
//        m5.write(ss);
//        assertTrue(ss.str() == "-4");
//        ss.str("");
//
//        m6.write(ss);
//        assertTrue(ss.str() == "-4(%eax,%ebx,4)");
//        ss.str("");
    }
};


class AsmMemCompareTest: public TestUnit {
public:
    AsmMemCompareTest(): TestUnit("Compare test") {}
    
    void run() noexcept override {
//        AsmRegister r1(AsmRegister::Type::eax);
//        AsmRegister r2(AsmRegister::Type::ebx);
//        AsmRegister r3(AsmRegister::Type::ecx);
//        
//        AsmIntConstant i1(12);
//        
//        AsmMemory m1(1, &r1, &r2, AsmMemory::ScaleT::one);
//        AsmMemory m2(1, &r1, &r2, AsmMemory::ScaleT::one);
//        AsmMemory m3(1, &r1, &r3, AsmMemory::ScaleT::one);
//        AsmMemory m4(1, &r3, &r2, AsmMemory::ScaleT::one);
//        AsmMemory m5(1, &r1, nullptr, AsmMemory::ScaleT::one);
//        AsmMemory m6(1, &r1, nullptr, AsmMemory::ScaleT::four);
//        AsmMemory m7(1, &r1, &r2, AsmMemory::ScaleT::four);
//        AsmMemory m8(1, nullptr, &r2, AsmMemory::ScaleT::one);
//        
//        assertTrue(m1.isEqualTo(&m2));
//        assertTrue(m1.isEqualTo(&m1));
//        assertTrue(m2.isEqualTo(&m1));
//        
//        assertFalse(m1.isEqualTo(&m3));
//        assertFalse(m1.isEqualTo(&m4));
//        assertFalse(m1.isEqualTo(&m5));
//        assertFalse(m1.isEqualTo(&m6));
//        assertFalse(m1.isEqualTo(&m7));
//        assertFalse(m1.isEqualTo(&m8));
//    
//        assertFalse(m3.isEqualTo(&m4));
//        assertFalse(m3.isEqualTo(&m5));
//        assertFalse(m3.isEqualTo(&m6));
//        assertFalse(m3.isEqualTo(&m7));
//        assertFalse(m3.isEqualTo(&m8));
//        
//        assertFalse(m4.isEqualTo(&m5));
//        assertFalse(m4.isEqualTo(&m6));
//        assertFalse(m4.isEqualTo(&m7));
//        assertFalse(m4.isEqualTo(&m8));
//        
//        assertTrue(m5.isEqualTo(&m6));
//        assertFalse(m5.isEqualTo(&m7));
//        assertFalse(m5.isEqualTo(&m8));
//        
//        assertFalse(m6.isEqualTo(&m7));
//        assertFalse(m6.isEqualTo(&m8));
//        
//        assertFalse(m7.isEqualTo(&m8));
//        
//        assertFalse(m1.isEqualTo(&r1));
//        assertFalse(m1.isEqualTo(&r2));
//        assertFalse(m1.isEqualTo(&r3));
//        assertFalse(m1.isEqualTo(&i1));
    }
};

vector<shared_ptr<TestUnit>> AsmMemoryTests::getTests() const noexcept {
    
    return {
        make_shared<AsmMemRepresentationTest>(),
        make_shared<AsmMemCompareTest>()
    };
}

