//
//  EnvironmentTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "EnvironmentTests.hpp"

#include "../../testCase/TestUnit.hpp"
#include "Logic.hpp"

using namespace std;


class CorrectUsage1 final: public TestUnit {
public:
    CorrectUsage1(): TestUnit("Correct Usage 1") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        
        Type const * type = env->getLatteInt();
        env->declareVariable("kot", type, 1, 3);
        type = env->getLatteBool();
        env->declareVariable("ma", type, 2, 3);
        type = env->getLatteString();
        env->declareVariable("Ala", type, 3, 3);
    }
};


class CorrectUsage2 final: public TestUnit {
public:
    CorrectUsage2(): TestUnit("Correct Usage 2") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        
        Type const * type = env->getLatteInt();
        env->declareVariable("kot", type, 1, 3);
        env->getVariableNamed("kot", false, 2, 3);
    }
};



class BuiltinTypes final: public TestUnit {
public:
    BuiltinTypes(): TestUnit("Builtin types") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        
        auto b1 = env->getLatteBool();
        auto i1 = env->getLatteInt();
        auto s1 = env->getLatteString();
        auto v1 = env->getLatteVoid();
        
        LatteBool b2;
        LatteInt i2;
        LatteString s2;
        LatteVoid v2;
        
        assertTrue(b1->isKindOf(&b2));
        assertTrue(b2.isKindOf(b1));
        
        assertTrue(i1->isKindOf(&i2));
        assertTrue(i2.isKindOf(i1));
        
        assertTrue(s1->isKindOf(&s2));
        assertTrue(s2.isKindOf(s1));
        
        assertTrue(v1->isKindOf(&v2));
        assertTrue(v2.isKindOf(v1));
    }
};


class NoSuchType final: public TestUnit {
public:
    NoSuchType(): TestUnit("No such type") {}
    
    void run() noexcept override {
        GlobalEnvironment env;
        try {
            env.getTypeNamed("Placki", 1, 2);
        } catch(NoSuchTypeError & error) {
            return;
        }
        assertTrue(false);
    }
};


class VariableRedeclaration final: public TestUnit {
public:
    VariableRedeclaration(): TestUnit("Variable redeclaration") {}
    
    void run() noexcept override {
        GlobalEnvironment gEnv;
        auto intT = gEnv.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = gEnv.declareFunction(mainInitializer, 1, 1);
        auto env = mainF->getEnvironment();
        try {
            auto type = env->getTypeNamed("int", 1, 2);
            env->declareVariable("kot", type, 1, 3);
            env->declareVariable("kot", type, 1, 3);
        } catch(VariableRedeclarationError & error) {
            return;
        }
        assertTrue(false);
    }
};


class UndefinedVariable final: public TestUnit {
public:
    UndefinedVariable(): TestUnit("Undefined variable") {}
    
    void run() noexcept override {
        GlobalEnvironment env;
        try {
            env.getVariableNamed("placki", false, 1, 2);
        } catch(NoSuchVariableError & error) {
            return;
        }
        assertTrue(false);
    }
};


vector<shared_ptr<TestUnit>> EnvironmentTests::getTests() const noexcept {
    return {
        make_shared<CorrectUsage1>(),
        make_shared<CorrectUsage2>(),
        make_shared<BuiltinTypes>(),
        make_shared<NoSuchType>(),
        make_shared<VariableRedeclaration>(),
        make_shared<UndefinedVariable>()
    };
}

