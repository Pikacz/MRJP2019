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
    ss << "    int a;" << endl;
    ss << "    a = readInt();" << endl;
//    ss << "    printInt(1 + 3 * 2 + a);" << endl;
//    ss << "    printInt(1);" << endl;
//    ss << "    return 0;" << endl;
    ss << "}" << endl;
    
//    ss << "int main() {" << endl;
//    ss << "    int hehe = fac(1);" << endl;
//    ss << "    printInt(hehe);" << endl;
//    ss << "    return 0;" << endl;
//    ss << "}" << endl;
//    ss << endl;
//    ss << "int fac(int a) {" << endl;
//    ss << "    int r;" << endl;
//    ss << "    int n;" << endl;
//    ss << "" << endl;
//    ss << "    r = 1;" << endl;
//    ss << "    n = a;" << endl;
//    ss << "    while (n > 0) {" << endl;
//    ss << "      r = r * n;" << endl;
//    ss << "      n = n - 1;" << endl;
//    ss << "    }" << endl;
//    ss << "    return r;" << endl;
//    ss << "}" << endl;
    
//    ss << "int main() {" << endl;
//    ss << "    printInt(fac(10));" << endl;
//    ss << "    printInt(rfac(10));" << endl;
//    ss << "    printInt(mfac(10));" << endl;
//    ss << "        printInt(ifac(10));" << endl;
//    ss << "        string r ; // just to test blocks " << endl;
//    ss << "    {" << endl;
//    ss << "      int n = 10;" << endl;
//    ss << "      int r = 1;" << endl;
//    ss << "      while (n>0) {" << endl;
//    ss << "        r = r * n;" << endl;
//    ss << "        n--;" << endl;
//    ss << "      }" << endl;
//    ss << "      printInt(r);" << endl;
//    ss << "    }" << endl;
//    ss << "    printString (repStr(\"=\",60));" << endl;
//    ss << "    printString (\"hello */\");" << endl;
//    ss << "        printString (\"/* world\") ;" << endl;
//    ss << "        return 0 ;" << endl;
//    ss << "}" << endl;
//    ss << "" << endl;
//    ss << "int fac(int a) {" << endl;
//    ss << "    int r;" << endl;
//    ss << "    int n;" << endl;
//    ss << "" << endl;
//    ss << "    r = 1;" << endl;
//    ss << "    n = a;" << endl;
//    ss << "    while (n > 0) {" << endl;
//    ss << "      r = r * n;" << endl;
//    ss << "      n = n - 1;" << endl;
//    ss << "    }" << endl;
//    ss << "    return r;" << endl;
//    ss << "}" << endl;
//    ss << "" << endl;
//    ss << "int rfac(int n) {" << endl;
//    ss << "    if (n == 0)" << endl;
//    ss << "      return 1;" << endl;
//    ss << "    else" << endl;
//    ss << "      return n * rfac(n-1);" << endl;
//    ss << "}" << endl;
//    ss << "" << endl;
//    ss << "int mfac(int n) {" << endl;
//    ss << "    if (n == 0)" << endl;
//    ss << "      return 1;" << endl;
//    ss << "    else" << endl;
//    ss << "      return n * nfac(n-1);" << endl;
//    ss << "}" << endl;
//    ss << "" << endl;
//    ss << "int nfac(int n) {" << endl;
//    ss << "    if (n != 0)" << endl;
//    ss << "      return mfac(n-1) * n;" << endl;
//    ss << "    else" << endl;
//    ss << "      return 1;" << endl;
//    ss << "}" << endl;
//    ss << "" << endl;
//    ss << "int ifac(int n) { return ifac2f(1,n); }" << endl;
//    ss << "" << endl;
//    ss << "int ifac2f(int l, int h) {" << endl;
//    ss << "        if (l == h)" << endl;
//    ss << "          return l;" << endl;
//    ss << "        if (l > h)" << endl;
//    ss << "          return 1;" << endl;
//    ss << "        int m;" << endl;
//    ss << "        m = (l + h) / 2;" << endl;
//    ss << "        return ifac2f(l,m) * ifac2f(m+1,h);" << endl;
//    ss << "}" << endl;
//    ss << "" << endl;
//    ss << "string repStr(string s, int n) {" << endl;
//    ss << "  string r = \"\";" << endl;
//    ss << "  int i = 0;" << endl;
//    ss << "  while(i<n) {" << endl;
//    ss << "    r = r + s;" << endl;
//    ss << "    i++;" << endl;
//    ss << "  }" << endl;
//    ss << " return r;" << endl;
//    ss << "}" << endl;
    
    
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
