//
//  BoolConstantTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "BoolConstantTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;

class BoolConstantTest final: public TestUnit {
public:
    BoolConstantTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        
        BoolConstant b1(true, env, 1, 1), b2(true, env, 1, 2), b3(false, env, 1, 3);
        
        assertTrue(b1.isKindOf(env->getLatteBool()));
        
        assertTrue(b1.isEqualTo(&b2));
        assertFalse(b1.isEqualTo(&b3));
        
        assertTrue(b1.getValue() == true);
        assertTrue(b3.getValue() == false);
    }
};


std::vector<std::shared_ptr<TestUnit> > BoolConstantTests::getTests() const noexcept {
    return {
        make_shared<BoolConstantTest>()
    };
}
