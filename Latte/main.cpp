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
#include <sstream>

using namespace std;



int main(int argc, const char * argv[]) {
    stringstream ss;
    ss << "int main() {" << endl;
    ss << "    int a = 2;" << endl;
    ss << "    a++;" << endl;
    ss << "    return a;" << endl;
    ss << "}" << endl;
    
    string str = ss.str();
    
//    antlr4::ANTLRInputStream input(str);
//    LatteLexer lexer(&input);
//    antlr4::CommonTokenStream tokens(&lexer);
//    tokens.fill();
//    LatteParser parser(&tokens);
//    cout.flush();
//    auto defs = parser.main()->topDef();
//    cout << defs.size() << endl;
//
//    auto m = defs[0]->function();
//    auto name = m->Identifier()->getText();
//    cout << name << endl;
    
    try {
        auto env = TopDefFactory::createFrom(str);
        list<unique_ptr<const AsmInstruction>> compiled;
        env->compile(compiled);
        
        
        for (auto it = compiled.begin(); it != compiled.end(); it++) {
            stringstream ss;
            it->get()->write(ss);
            cout << ss.str();
        }
        
    } catch (StaticCheckError & error) {
        cerr << error.what();
    } catch (ParserError & error) {
        cerr << error.what();
    }
    
    
    return 0;
}
