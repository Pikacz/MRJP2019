//
//  main.cpp
//  Latte
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//
#include "Logic.hpp"

#include <iostream>
#include <bitset>
#include <string>
#include <cstdio>
#include <list>
#include <memory>
#include <vector>
#include <list>
#include <sstream>

using namespace std;

string getOutputBaseName(string str) {
    string base;
    size_t dot = str.find_last_of(".");
    
    if (dot == string::npos) {
        base = str;
    } else {
        base = str.substr(0, dot);
    }
    
    return base;
}





int main(int argc, const char * argv[]) {
    
    stringstream inputStream;
    if (argc > 0) {
        inputStream << argv[0];
    }
    string inName = inputStream.str();
    string baseName = getOutputBaseName(inName);
    
    
    cout << getOutputBaseName("") << endl;
    
    stringstream ss;
    
    ifstream input(inName);
    ss << input.rdbuf();
    string str = ss.str();
    
    
    
    try {
        auto env = TopDefFactory::createFrom(str);
        list<unique_ptr<const AsmInstruction>> compiled;
        env->compile(compiled);
        
        cerr << "OK" << endl;
        
        string asmName = baseName + ".s";
        ostream * asmStream = &cout;
        if (baseName != "") {
            asmStream = new ofstream(asmName);
        }
        
        for (auto it = compiled.begin(); it != compiled.end(); it++) {
            stringstream ss;
            it->get()->write(ss);
            (*asmStream) << ss.str();
        }
        
        if (baseName != "") {
            ((ofstream *)asmStream)->close();
            delete asmStream;
            
            string compile = "clang++ latte_lib/latte_lib.o" + asmName + " -o " + baseName;
            
            system(compile.c_str());
        }
        
    } catch (StaticCheckError & error) {
        cerr << "ERROR" << endl;
        cerr << error.what();
    } catch (ParserError & error) {
        cerr << "ERROR" << endl;
        cerr << error.what();
    } catch (string & s) {
        cerr << "OK" << endl;
        cerr << "correct program but compilator is not finished" << endl;
        cerr << s << endl;
    }
    
    
    
    return 0;
}
