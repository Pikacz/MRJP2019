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
        
        unique_ptr<const Expression> justOne = make_unique<IntConstant>(3, fEnv, 2, 4);
        unique_ptr<const Expression> justOne2 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne3 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne4 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justOne5 = make_unique<IntConstant>(1, fEnv, 2, 4);
        unique_ptr<const Expression> justThree = make_unique<IntConstant>(5, fEnv, 2, 7);
        
//        unique_ptr<const Expression> justAdd4 = make_unique<IntAdd>(
//            fEnv, 2, 5, move(justOne4), move(justOne5)
//        );
//        unique_ptr<const Expression> justAdd3 = make_unique<IntAdd>(
//            fEnv, 2, 5, move(justOne3), move(justAdd4)
//        );
//        unique_ptr<const Expression> justAdd2 = make_unique<IntAdd>(
//            fEnv, 2, 5, move(justOne2), move(justAdd3)
//        );
//        unique_ptr<const Expression> justAdd = make_unique<IntAdd>(
//            fEnv, 2, 5, move(justOne), move(justAdd2)
//        );
        
        unique_ptr<const Expression> justMul = make_unique<IntMod>(
            fEnv, 2, 5, move(justThree), move(justOne)
        );
        
        unique_ptr<const Statement> returnOne = make_unique<ReturnStatement>(
            2, 4, fEnv, move(justMul)
        );
        
        vector<unique_ptr<const Statement>> body;
        body.push_back(move(returnOne));
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
