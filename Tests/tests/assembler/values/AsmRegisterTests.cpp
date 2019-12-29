//
//  AsmRegisterTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "AsmRegisterTests.hpp"
#include "../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

#include <sstream>

using namespace std;

class AsmRegRepresentationTest final: public TestUnit {
public:
    AsmRegRepresentationTest(): TestUnit("Representation test") {}
    
    void run() noexcept override {
        stringstream ss;
//        AsmRegister eax(AsmRegister::Type::eax);
//        AsmRegister ebx(AsmRegister::Type::ebx);
//        AsmRegister ecx(AsmRegister::Type::ecx);
//        AsmRegister edx(AsmRegister::Type::edx);
//        AsmRegister esi(AsmRegister::Type::esi);
//        AsmRegister edi(AsmRegister::Type::edi);
//        AsmRegister esp(AsmRegister::Type::esp);
//        AsmRegister ebp(AsmRegister::Type::ebp);
//
//        eax.write(ss);
//        assertTrue(ss.str() == "%eax");
//        ss.str("");
//
//        ebx.write(ss);
//        assertTrue(ss.str() == "%ebx");
//        ss.str("");
//
//        ecx.write(ss);
//        assertTrue(ss.str() == "%ecx");
//        ss.str("");
//
//        edx.write(ss);
//        assertTrue(ss.str() == "%edx");
//        ss.str("");
//
//        esi.write(ss);
//        assertTrue(ss.str() == "%esi");
//        ss.str("");
//
//        edi.write(ss);
//        assertTrue(ss.str() == "%edi");
//        ss.str("");
//
//        esp.write(ss);
//        assertTrue(ss.str() == "%esp");
//        ss.str("");
//
//        ebp.write(ss);
//        assertTrue(ss.str() == "%ebp");
//        ss.str("");
    }
};


class AsmRegCompareTest: public TestUnit {
public:
    AsmRegCompareTest(): TestUnit("Compare test") {}
    
    void run() noexcept override {
//        AsmRegister r1(AsmRegister::Type::eax);
//        AsmRegister r2(AsmRegister::Type::eax);
//        AsmRegister r3(AsmRegister::Type::ebx);
//        
//        AsmIntConstant i1(12);
//        
//        AsmMemory m1(1, &r1, &r2, AsmMemory::ScaleT::one);
//        
//        assertTrue(r1.isEqualTo(&r2));
//        assertTrue(r1.isEqualTo(&r1));
//        assertTrue(r2.isEqualTo(&r1));
//        
//        assertFalse(r1.isEqualTo(&r3));
//        assertFalse(r3.isEqualTo(&r1));
//        assertFalse(r1.isEqualTo(&i1));
//        assertFalse(r1.isEqualTo(&m1));
    }
};

vector<shared_ptr<TestUnit>> AsmRegisterTests::getTests() const noexcept {
    return {
        make_shared<AsmRegRepresentationTest>(),
        make_shared<AsmRegCompareTest>()
    };
}
