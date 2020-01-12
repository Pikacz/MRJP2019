//
//  main.cpp
//  Latte
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include <iostream>
#include "Logic.hpp"

#include <list>
#include <memory>
#include <vector>
#include <list>

using namespace std;



int main(int argc, const char * argv[]) {
    try {
        GlobalEnvironment env;
        auto intT = env.getLatteInt();
        FunctionInitializer mainInitializer(intT, "main", {});
        auto mainF = env.declareFunction(mainInitializer, 1, 1);
        auto fEnv = mainF->getEnvironment();
        
        vector<unique_ptr<const Statement>> body;
        
        { // int a = 0;
            unique_ptr<const Expression> just0 = make_unique<IntConstant>(0, fEnv, 1, 2);
            unique_ptr<const Statement> decA = make_unique<DeclareStatement>(4, 3, fEnv, "int", "a");
            body.push_back(move(decA));
            auto aVar = fEnv->getVariableNamed("a", 4, 3);
            unique_ptr<const Statement> setA = make_unique<AssignementStatement>(4, 3, aVar, move(just0));
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
            auto setA = make_unique<AssignementStatement>(4, 3, aVar, move(incA));
            
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
        
        
        list<unique_ptr<const AsmInstruction>> compiled;
        env.compile(compiled);
        for (auto it = compiled.begin(); it != compiled.end(); it++) {
            stringstream ss;
            it->get()->write(ss);
            cout << ss.str();
        }
        
        
    } catch (StaticCheckError& error) {
        cout << error.what();
    }
    return 0;
}
