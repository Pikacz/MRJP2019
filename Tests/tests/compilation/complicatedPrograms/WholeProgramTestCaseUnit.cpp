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

static void createLatteLib() noexcept;

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
    assertTrue(pOut == out);
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


static void createLatteLib() noexcept {
    static bool initialized = false;
    if (initialized) return;
    initialized = true;
    
    ofstream headerFile("latte_lib.hpp");
    headerFile << "void printInt(long long int l);" << endl;
    headerFile << "void printString(char *);" << endl;
    headerFile << "void error();" << endl;
    headerFile << "long long int readInt();" << endl;
    headerFile << "char * readString();" << endl;
    headerFile.close();
    
    ofstream codeFile("latte_lib.cpp");
    codeFile << "#include \"latte_lib.hpp\"" << endl;
    codeFile << endl;
    codeFile << "#include <iostream>" << endl;
    codeFile << "#include <string>" << endl;
    codeFile << "#include <cstring>" << endl;
    codeFile << "#include <cassert>" << endl;
    codeFile << endl;
    codeFile << "using namespace std;" << endl;
    codeFile << endl;
    codeFile << endl;
    codeFile << "void printInt(long long int i) {" << endl;
    codeFile << "    cout << i << endl;" << endl;
    codeFile << "}" << endl;
    codeFile << endl;
    codeFile << "void printString(char * s) {" << endl;
    codeFile << "    cout << s << endl;" << endl;
    codeFile << "}" << endl;
    codeFile << endl;
    codeFile << "void error() {" << endl;
    codeFile << "    assert(false);" << endl;
    codeFile << "}" << endl;
    codeFile << endl;
    codeFile << "long long int readInt() {" << endl;
    codeFile << "    long long int val;" << endl;
    codeFile << "    cin >> val;" << endl;
    codeFile << "    return val;" << endl;
    codeFile << "}" << endl;
    codeFile << endl;
    codeFile << "char * readString() {" << endl;
    codeFile << "    string str;" << endl;
    codeFile << "    cin >> str;" << endl;
    codeFile << "    char * cstr = new char [str.length()+1];" << endl;
    codeFile << "    strcpy(cstr, str.c_str());" << endl;
    codeFile << "    return cstr;" << endl;
    codeFile << "}" << endl;
    codeFile.close();
    
    
    system("clang++  -O3 latte_lib.hpp latte_lib.cpp -c");
}
