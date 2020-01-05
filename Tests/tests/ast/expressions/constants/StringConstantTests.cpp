//
//  StringConstantTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "StringConstantTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;

class StringConstantTest final: public TestUnit {
public:
    StringConstantTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        
        StringConstant s1("ala", env, 1, 1), s2("ala", env, 1, 2), s3("kota", env, 1, 3);
        
        assertTrue(s1.isKindOf(env->getLatteString()));
        
        assertTrue(s1.isEqualTo(&s2));
        assertFalse(s1.isEqualTo(&s3));
        
        assertTrue(s1.getValue() == "ala");
        assertTrue(s3.getValue() == "kota");
    }
};


std::vector<std::shared_ptr<TestUnit> > StringConstantTests::getTests() const noexcept {
    return {
        make_shared<StringConstantTest>()
    };
}
