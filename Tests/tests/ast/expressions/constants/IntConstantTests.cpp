//
//  IntConstantTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "IntConstantTests.hpp"

#include "../../../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;

class IntConstantTest final: public TestUnit {
public:
    IntConstantTest(): TestUnit("Test 1") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        
        IntConstant i1(1, env, 1, 1), i2(1, env, 1, 2), i3(0, env, 1, 3);
        
        assertTrue(i1.isKindOf(env->getLatteInt()));
        
        assertTrue(i1.isEqualTo(&i2));
        assertFalse(i1.isEqualTo(&i3));
        
        assertTrue(i1.getValue() == 1);
        assertTrue(i3.getValue() == 0);
    }
};


std::vector<std::shared_ptr<TestUnit> > IntConstantTests::getTests() const noexcept {
    return {
        make_shared<IntConstantTest>()
    };
}
