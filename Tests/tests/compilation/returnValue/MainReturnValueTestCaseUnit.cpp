//
//  MainReturnValueTestCaseUnit.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "MainReturnValueTestCaseUnit.hpp"
#include <cstdio>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>


using namespace std;

void MainReturnValueTestCaseUnit::run() noexcept {
    GlobalEnvironment env;
    fillEnv(env);
    
    list<unique_ptr<const AsmInstruction>> compiled;
    env.compile(compiled);
    
    std::ofstream o("tmp.s");
    
    for (auto it = compiled.begin(); it != compiled.end(); it++) {
        stringstream ss;
        it->get()->write(ss);
        o << ss.str();
    }
    o.close();
    system("clang++ tmp.s -o elo");
    int result = system("./elo > xx.txt");
    result = WEXITSTATUS(result);
    
//    cout << endl;
//    cout << endl;
//    string line;
//    ifstream myfile ("tmp.s");
//    if (myfile.is_open())
//    {
//      while ( getline (myfile,line) )
//      {
//        cout << line << '\n';
//      }
//      myfile.close();
//    }
//    cout << endl;
//    cout << endl;
    
    system("rm -rf tmp.s elo xx.txt");
    assertTrue(result == expectedExitCode());
}
