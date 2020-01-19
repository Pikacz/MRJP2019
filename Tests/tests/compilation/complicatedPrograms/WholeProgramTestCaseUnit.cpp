//
//  WholeProgramTestCaseUnit.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "WholeProgramTestCaseUnit.hpp"

#include <cstdio>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;


void WholeProgramTestCaseUnit::run() noexcept {
    createLatteLib();
    
    stringstream code;
    fillCode(code);
    auto env = TopDefFactory::createFrom(code.str());

    list<unique_ptr<const AsmInstruction>> compiled;
    env->compile(compiled);
    
    std::ofstream asmFile("tmp.s");
    
    for (auto it = compiled.begin(); it != compiled.end(); it++) {
        stringstream ss;
        it->get()->write(ss);
        asmFile << ss.str();
    }
    asmFile.close();
    
    ofstream inFile("tmp.in");
    fillInput(inFile);
    inFile.close();
    
    stringstream outS;
    fillOutput(outS);
    string out = outS.str();
    
    system("clang++ tmp.s latte_lib.o -o elo");
    int result = system("./elo < tmp.in > xx.txt");
    result = WEXITSTATUS(result);
    
    
    ifstream programOutS("xx.txt");
    stringstream programOutSS;
    programOutSS << programOutS.rdbuf();
    
    
    
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
    
    system("rm -rf tmp.s elo xx.txt tmp.in");
    
    string pOut = programOutSS.str();
    
    if (pOut != out) {
        cout << "wyplułem:" << endl;
        cout << pOut << endl;
        cout << "zamiast:" << endl;
        cout << out << endl;
        cout.flush();
        assertTrue(false);
    }
    int expExitCode = expectedExitCode();
    assertTrue(result == expExitCode);
}


void WholeProgramTestCaseUnit::fillInput(ostream & ss) const noexcept {
    
}

void WholeProgramTestCaseUnit::fillOutput(ostream & ss) const noexcept {
    
}

int WholeProgramTestCaseUnit::expectedExitCode() const noexcept {
    return 0;
}

