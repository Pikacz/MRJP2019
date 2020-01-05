//
//  SingleExpression.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "SingleExpression.hpp"
#include "MainReturnValueTestCaseUnit.hpp"

#include <memory>
#include <vector>

using namespace std;

// return 1
class SimpleExpr1 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr1(): MainReturnValueTestCaseUnit("return 1") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justOne = make_unique<IntConstant>(1, fEnv, 2, 4);
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justOne)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 1;
    }
};



// return 1 + 2
class SimpleExpr2 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr2(): MainReturnValueTestCaseUnit("return 1 + 2") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justOne = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justTwo = make_unique<IntConstant>(2, fEnv, 2, 7);
        
        unique_ptr<const Expression> justAdd = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne), move(justTwo)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justAdd)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 3;
    }
};


// return 1 + (2 + (2 + (2 + (2 + 2))))
class SimpleExpr3 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr3(): MainReturnValueTestCaseUnit("return 1 + (2 + (2 + (2 + (2 + 2))))") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justOne = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justTwo = make_unique<IntConstant>(2, fEnv, 2, 7);
        unique_ptr<const Expression> justTwo2 = make_unique<IntConstant>(2, fEnv, 2, 7);
        unique_ptr<const Expression> justTwo3 = make_unique<IntConstant>(2, fEnv, 2, 7);
        unique_ptr<const Expression> justTwo4 = make_unique<IntConstant>(2, fEnv, 2, 7);
        unique_ptr<const Expression> justTwo5 = make_unique<IntConstant>(2, fEnv, 2, 7);
        unique_ptr<const Expression> justAdd4 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justTwo4), move(justTwo5)
        );
        unique_ptr<const Expression> justAdd3 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justTwo3), move(justAdd4)
        );
        unique_ptr<const Expression> justAdd2 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justTwo2), move(justAdd3)
        );
        unique_ptr<const Expression> justAdd1 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justTwo), move(justAdd2)
        );
        
        unique_ptr<const Expression> justAdd = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne), move(justAdd1)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justAdd)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 11;
    }
};

// return 3 - 1
class SimpleExpr4 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr4(): MainReturnValueTestCaseUnit("return 3 - 1") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justOne = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justThree = make_unique<IntConstant>(3, fEnv, 2, 7);
        
        unique_ptr<const Expression> justSub = make_unique<IntSub>(
            fEnv, 2, 5, move(justThree), move(justOne)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justSub)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 2;
    }
};

// return 6 - (1 + (1 + (1 + (1 + 1))))
class SimpleExpr5 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr5(): MainReturnValueTestCaseUnit("return 6 - (1 + (1 + (1 + (1 + 1))))") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justOne = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne2 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne3 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne4 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne5 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justSix = make_unique<IntConstant>(6, fEnv, 2, 7);
        
        unique_ptr<const Expression> justAdd4 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne4), move(justOne5)
        );
        unique_ptr<const Expression> justAdd3 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne3), move(justAdd4)
        );
        unique_ptr<const Expression> justAdd2 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne2), move(justAdd3)
        );
        unique_ptr<const Expression> justAdd = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne), move(justAdd2)
        );
        
        unique_ptr<const Expression> justSub = make_unique<IntSub>(
            fEnv, 2, 5, move(justSix), move(justAdd)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justSub)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 1;
    }
};


// return 2 * 6
class SimpleExpr6 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr6(): MainReturnValueTestCaseUnit("return 2 * 6") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justSix = make_unique<IntConstant>(6, fEnv, 2, 4);
        unique_ptr<const Expression> justTwo = make_unique<IntConstant>(2, fEnv, 2, 7);
        
        unique_ptr<const Expression> justMul = make_unique<IntMul>(
            fEnv, 2, 5, move(justTwo), move(justSix)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justMul)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 12;
    }
};


// return 3 / 2
class SimpleExpr7 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr7(): MainReturnValueTestCaseUnit("return 3 / 2") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justThree = make_unique<IntConstant>(3, fEnv, 2, 4);
        unique_ptr<const Expression> justTwo = make_unique<IntConstant>(2, fEnv, 2, 7);
        
        unique_ptr<const Expression> justDiv = make_unique<IntDiv>(
            fEnv, 2, 5, move(justThree), move(justTwo)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justDiv)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 1;
    }
};



// return ((1 + (1 + 1)) * 2) / ((1 - 2) + (1 + (1 + 1)))
//            2    1     1    1     1    5    4    3
class SimpleExpr8 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr8(): MainReturnValueTestCaseUnit("return ((1 + (1 + 1)) * 2) / ((1 - 2) + (1 + (1 + 1)))") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justOne1 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne2 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne3 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne4 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne5 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne6 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne7 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justTwo1 = make_unique<IntConstant>(2, fEnv, 2, 7);
        unique_ptr<const Expression> justTwo2 = make_unique<IntConstant>(2, fEnv, 2, 7);
        
        unique_ptr<const Expression> justAdd1 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne2), move(justOne3)
        );
        
        unique_ptr<const Expression> justAdd2 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne1), move(justAdd1)
        );
        
        unique_ptr<const Expression> justMul1 = make_unique<IntMul>(
            fEnv, 2, 5, move(justAdd2), move(justTwo1)
        );
        
        unique_ptr<const Expression> justAdd3 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne6), move(justOne7)
        );
        
        unique_ptr<const Expression> justAdd4 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justOne5), move(justAdd3)
        );
        
        unique_ptr<const Expression> justSub1 = make_unique<IntSub>(
            fEnv, 2, 5, move(justOne4), move(justTwo2)
        );
        
        unique_ptr<const Expression> justAdd5 = make_unique<IntAdd>(
            fEnv, 2, 5, move(justSub1), move(justAdd4)
        );
        
        unique_ptr<const Expression> justDiv1 = make_unique<IntDiv>(
            fEnv, 2, 5, move(justMul1), move(justAdd5)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justDiv1)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 3;
    }
};


// return 5 % 3
class SimpleExpr9 final: public MainReturnValueTestCaseUnit {
public:
    SimpleExpr9(): MainReturnValueTestCaseUnit("return 5 % 3") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();

        unique_ptr<const Expression> justThree = make_unique<IntConstant>(3, fEnv, 2, 4);
        unique_ptr<const Expression> justFive = make_unique<IntConstant>(5, fEnv, 2, 7);
        
        unique_ptr<const Expression> justMod = make_unique<IntMod>(
            fEnv, 2, 5, move(justFive), move(justThree)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justMod)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 2;
    }
};


vector<shared_ptr<TestUnit> > SingleExpression::getTests() const noexcept {
    return {
        make_shared<SimpleExpr1>(),
        make_shared<SimpleExpr2>(),
        make_shared<SimpleExpr3>(),
        make_shared<SimpleExpr4>(),
        make_shared<SimpleExpr5>(),
        make_shared<SimpleExpr6>(),
        make_shared<SimpleExpr7>(),
        make_shared<SimpleExpr8>(),
        make_shared<SimpleExpr9>()
    };
}
