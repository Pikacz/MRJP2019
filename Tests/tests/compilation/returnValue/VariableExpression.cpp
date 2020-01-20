//
//  VariableExpression.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 06/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "VariableExpression.hpp"
#include "MainReturnValueTestCaseUnit.hpp"

#include <memory>
#include <vector>

using namespace std;

// int a = 3 + 4
// return a
class VarExpr1 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr1(): MainReturnValueTestCaseUnit("var test 1") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        unique_ptr<const Expression> val1 = make_unique<IntConstant>(3, fEnv, 2, 4);
        unique_ptr<const Expression> val2 = make_unique<IntConstant>(4, fEnv, 2, 4);
        ;
        
        unique_ptr<const Expression> expr1 = make_unique<IntAdd>(
            fEnv, 2, 5, move(val1), move(val2)
        );
        
        
        unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
        body.push_back(move(decA));
        
        auto aVar = fEnv->getVariableNamed("a", 4, 3);
        unique_ptr<const Statement> setA = make_unique<AssignementStatement>(
                4, 3, make_unique<VarExpression>(3, 6, aVar), move(expr1), true
        );
        body.push_back(move(setA));
        
        unique_ptr<const Expression> expr2 = make_unique<VarExpression>(3, 6, aVar);
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(expr2)
        );
        
        
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 7;
    }
};


class VarExpr2 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr2(): MainReturnValueTestCaseUnit("var test 2") {}
    
    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        unique_ptr<const Expression> val1 = make_unique<IntConstant>(3, fEnv, 2, 4);
        unique_ptr<const Expression> val2 = make_unique<IntConstant>(4, fEnv, 2, 4);
        ;
        
        unique_ptr<const Expression> expr1 = make_unique<IntAdd>(
            fEnv, 2, 5, move(val1), move(val2)
        );
        
        
        unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
        body.push_back(move(decA));
        unique_ptr<const Statement> tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "b");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "c");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "d");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "e");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "f");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "g");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "h");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "i");
        body.push_back(move(tmp));
        tmp = make_unique<DeclareStatement>(4, 3, fEnv, intT, "j");
        body.push_back(move(tmp));
        
        auto aVar = fEnv->getVariableNamed("i", 4, 3);
        unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(expr1), true);
        body.push_back(move(setA));
        
        unique_ptr<const Expression> expr2 = make_unique<VarExpression>(3, 6, aVar);
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(expr2)
        );
        
        
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }
    
    int expectedExitCode() const noexcept override {
        return 7;
    }
};


class VarExpr3 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr3(): MainReturnValueTestCaseUnit("var test 3") {}

    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
        body.push_back(move(decA));
        
        unique_ptr<BlockStatement> block = make_unique<BlockStatement>(4, 3, fEnv);
        auto bEnv = block.get()->getEnvironment();
        vector<unique_ptr<const Statement>> blockBody;
        unique_ptr<const Statement> decB = make_unique<DeclareStatement>(4, 3, bEnv, intT, "b");
        blockBody.push_back(move(decB));
        unique_ptr<const Statement> decC = make_unique<DeclareStatement>(4, 3, bEnv, intT, "c");
        blockBody.push_back(move(decC));
        auto bVar = bEnv->getVariableNamed("b", 4, 3);
        unique_ptr<const Expression> val1 = make_unique<IntConstant>(3, bEnv, 2, 4);
        unique_ptr<const Statement> setB = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, bVar), move(val1), true);
        blockBody.push_back(move(setB));
        auto cVar = bEnv->getVariableNamed("c", 4, 3);
        unique_ptr<const Expression> val2 = make_unique<IntConstant>(4, bEnv, 2, 4);
        unique_ptr<const Statement> setC = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, cVar), move(val2), true);
        blockBody.push_back(move(setC));
        unique_ptr<const Expression> exprB = make_unique<VarExpression>(3, 6, bVar);
        unique_ptr<const Expression> exprC = make_unique<VarExpression>(3, 6, cVar);
        unique_ptr<const Expression> expr1 = make_unique<IntAdd>(
            bEnv, 2, 5, move(exprB), move(exprC)
        );
        auto aVar = bEnv->getVariableNamed("a", 4, 3);
        unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(expr1), true);
        blockBody.push_back(move(setA));
        block.get()->completeWith(move(blockBody));
        
        body.push_back(move(block));
        unique_ptr<const Expression> expr2 = make_unique<VarExpression>(3, 6, aVar);
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(expr2)
        );
        
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }

    int expectedExitCode() const noexcept override {
        return 7;
    }
};


class VarExpr4 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr4(): MainReturnValueTestCaseUnit("var test 4") {}

    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
        body.push_back(move(decA));
        
        {
            unique_ptr<BlockStatement> block = make_unique<BlockStatement>(4, 3, fEnv);
            auto bEnv = block.get()->getEnvironment();
            vector<unique_ptr<const Statement>> blockBody;
            unique_ptr<const Statement> decB = make_unique<DeclareStatement>(4, 3, bEnv, intT, "b");
            blockBody.push_back(move(decB));
            unique_ptr<const Statement> decC = make_unique<DeclareStatement>(4, 3, bEnv, intT, "c");
            blockBody.push_back(move(decC));
            auto bVar = bEnv->getVariableNamed("b", 4, 3);
            unique_ptr<const Expression> val1 = make_unique<IntConstant>(3, bEnv, 2, 4);
            unique_ptr<const Statement> setB = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, bVar), move(val1), true);
            blockBody.push_back(move(setB));
            auto cVar = bEnv->getVariableNamed("c", 4, 3);
            unique_ptr<const Expression> val2 = make_unique<IntConstant>(2, bEnv, 2, 4);
            unique_ptr<const Statement> setC = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, cVar), move(val2), true);
            blockBody.push_back(move(setC));
            unique_ptr<const Expression> exprB = make_unique<VarExpression>(3, 6, bVar);
            unique_ptr<const Expression> exprC = make_unique<VarExpression>(3, 6, cVar);
            unique_ptr<const Expression> expr1 = make_unique<IntAdd>(
                bEnv, 2, 5, move(exprB), move(exprC)
            );
            auto aVar = bEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(expr1), true);
            blockBody.push_back(move(setA));
            block.get()->completeWith(move(blockBody));
            body.push_back(move(block));
        }
        
        {
            unique_ptr<BlockStatement> block = make_unique<BlockStatement>(4, 3, fEnv);
            auto bEnv = block.get()->getEnvironment();
            vector<unique_ptr<const Statement>> blockBody;
            unique_ptr<const Statement> decD = make_unique<DeclareStatement>(4, 3, bEnv, intT, "d");
            blockBody.push_back(move(decD));
            
            auto dVar = bEnv->getVariableNamed("d", 4, 3);
            
            unique_ptr<const Expression> val1 = make_unique<IntConstant>(2, bEnv, 2, 4);
            unique_ptr<const Statement> setD = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, dVar), move(val1), true);
            blockBody.push_back(move(setD));
            
            unique_ptr<const Expression> exprD = make_unique<VarExpression>(3, 6, dVar);
            auto aVar1 = bEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Expression> exprA = make_unique<VarExpression>(3, 6, aVar1);
            unique_ptr<const Expression> expr1 = make_unique<IntAdd>(
                bEnv, 2, 5, move(exprD), move(exprA)
            );
            auto aVar = bEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(expr1), true);
            blockBody.push_back(move(setA));
            block.get()->completeWith(move(blockBody));
            body.push_back(move(block));
        }
        
        
        auto aVar = fEnv->getVariableNamed("a", 4, 3);
        unique_ptr<const Expression> expr3 = make_unique<VarExpression>(3, 6, aVar);
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(expr3)
        );
        
        body.push_back(move(returnOne));
        mainF->completeWith(move(body));
    }

    int expectedExitCode() const noexcept override {
        return 7;
    }
};


// int a = 0;
// while (a < 10) a = a + 1;
// return a;
class VarExpr5 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr5(): MainReturnValueTestCaseUnit("var test 5") {}

    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        { // int a = 0;
            unique_ptr<const Expression> just0 = make_unique<IntConstant>(0, fEnv, 1, 2);
            unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
            body.push_back(move(decA));
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(just0), true);
            body.push_back(move(setA));
        }
        
        {
            // while (a < 10) a = a + 1;
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            auto aExpr = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Expression> just10 = make_unique<IntConstant>(10, fEnv, 1, 2);
            auto boolExpr = make_unique<CompareLess>(fEnv, 1, 2, move(aExpr), move(just10));
            
            auto aExpr2 = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Expression> just1 = make_unique<IntConstant>(1, fEnv, 1, 2);
            auto incA = make_unique<IntAdd>(fEnv, 1, 2, move(aExpr2), move(just1));
            auto setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(incA), false);
            
            auto wh = make_unique<WhileStatement>(1, 2, fEnv, move(boolExpr), move(setA));
            body.push_back(move(wh));
        }
        
        
        { // return a;
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            auto aExpr = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Statement> ret = make_unique<ReturnStatement>(
                2, 4, fEnv, move(aExpr)
            );
            body.push_back(move(ret));
        }
        
        mainF->completeWith(move(body));
    }

    int expectedExitCode() const noexcept override {
        return 10;
    }
};


// int a = 0;
// while (a <= 10) a = a + 1;
// return a;
class VarExpr6 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr6(): MainReturnValueTestCaseUnit("var test 6") {}

    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        { // int a = 0;
            unique_ptr<const Expression> just0 = make_unique<IntConstant>(0, fEnv, 1, 2);
            unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
            body.push_back(move(decA));
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(just0), true);
            body.push_back(move(setA));
        }
        
        {
            // while (a <= 10) a = a + 1;
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            auto aExpr = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Expression> just10 = make_unique<IntConstant>(10, fEnv, 1, 2);
            auto boolExpr = make_unique<CompareLessEqual>(fEnv, 1, 2, move(aExpr), move(just10));
            
            auto aExpr2 = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Expression> just1 = make_unique<IntConstant>(1, fEnv, 1, 2);
            auto incA = make_unique<IntAdd>(fEnv, 1, 2, move(aExpr2), move(just1));
            auto setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(incA), false);
            
            auto wh = make_unique<WhileStatement>(1, 2, fEnv, move(boolExpr), move(setA));
            body.push_back(move(wh));
        }
        
        
        { // return a;
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            auto aExpr = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Statement> ret = make_unique<ReturnStatement>(
                2, 4, fEnv, move(aExpr)
            );
            body.push_back(move(ret));
        }
        
        mainF->completeWith(move(body));
    }

    int expectedExitCode() const noexcept override {
        return 11;
    }
};


// int a = 100;
// while (a <= 10) a = a + 1;
// return a;
class VarExpr7 final: public MainReturnValueTestCaseUnit {
public:
    VarExpr7(): MainReturnValueTestCaseUnit("var test 7") {}

    void fillEnv(GlobalEnvironment & env) const noexcept override {
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        { // int a = 0;
            unique_ptr<const Expression> just0 = make_unique<IntConstant>(100, fEnv, 1, 2);
            unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, intT, "a");
            body.push_back(move(decA));
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(just0), true);
            body.push_back(move(setA));
        }
        
        {
            // while (a <= 10) a = a + 1;
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            auto aExpr = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Expression> just10 = make_unique<IntConstant>(10, fEnv, 1, 2);
            auto boolExpr = make_unique<CompareLessEqual>(fEnv, 1, 2, move(aExpr), move(just10));
            
            auto aExpr2 = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Expression> just1 = make_unique<IntConstant>(1, fEnv, 1, 2);
            auto incA = make_unique<IntAdd>(fEnv, 1, 2, move(aExpr2), move(just1));
            auto setA = make_unique<AssignementStatement>(4, 3, make_unique<VarExpression>(3, 6, aVar), move(incA), false);
            
            auto wh = make_unique<WhileStatement>(1, 2, fEnv, move(boolExpr), move(setA));
            body.push_back(move(wh));
        }
        
        
        { // return a;
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            auto aExpr = make_unique<VarExpression>(3, 6, aVar);
            unique_ptr<const Statement> ret = make_unique<ReturnStatement>(
                2, 4, fEnv, move(aExpr)
            );
            body.push_back(move(ret));
        }
        
        mainF->completeWith(move(body));
    }

    int expectedExitCode() const noexcept override {
        return 100;
    }
};


vector<shared_ptr<TestUnit> > VariableExpression::getTests() const noexcept {
    return {
        make_shared<VarExpr1>(),
        make_shared<VarExpr2>(),
        make_shared<VarExpr3>(),
        make_shared<VarExpr4>(),
        make_shared<VarExpr5>(),
        make_shared<VarExpr6>(),
        make_shared<VarExpr7>()
    };
}
