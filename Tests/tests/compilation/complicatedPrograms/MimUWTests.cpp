//
//  MimUWTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 18/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "MimUWTests.hpp"
#include "WholeProgramTestCaseUnit.hpp"

#include <memory>
#include <vector>

using namespace std;

class MimUWTest1 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest1(): WholeProgramTestCaseUnit("MIM UW 1") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        
        ss << "int main() {" << endl;
        ss << "    printInt(fac(10));" << endl;
        ss << "    printInt(rfac(10));" << endl;
        ss << "    printInt(mfac(10));" << endl;
        ss << "        printInt(ifac(10));" << endl;
        ss << "        string r ; // just to test blocks " << endl;
        ss << "    {" << endl;
        ss << "      int n = 10;" << endl;
        ss << "      int r = 1;" << endl;
        ss << "      while (n>0) {" << endl;
        ss << "        r = r * n;" << endl;
        ss << "        n--;" << endl;
        ss << "      }" << endl;
        ss << "      printInt(r);" << endl;
        ss << "    }" << endl;
        ss << "    printString (repStr(\"=\",60));" << endl;
        ss << "    printString (\"hello */\");" << endl;
        ss << "        printString (\"/* world\") ;" << endl;
        ss << "        return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int fac(int a) {" << endl;
        ss << "    int r;" << endl;
        ss << "    int n;" << endl;
        ss << "" << endl;
        ss << "    r = 1;" << endl;
        ss << "    n = a;" << endl;
        ss << "    while (n > 0) {" << endl;
        ss << "      r = r * n;" << endl;
        ss << "      n = n - 1;" << endl;
        ss << "    }" << endl;
        ss << "    return r;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int rfac(int n) {" << endl;
        ss << "    if (n == 0)" << endl;
        ss << "      return 1;" << endl;
        ss << "    else" << endl;
        ss << "      return n * rfac(n-1);" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int mfac(int n) {" << endl;
        ss << "    if (n == 0)" << endl;
        ss << "      return 1;" << endl;
        ss << "    else" << endl;
        ss << "      return n * nfac(n-1);" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int nfac(int n) {" << endl;
        ss << "    if (n != 0)" << endl;
        ss << "      return mfac(n-1) * n;" << endl;
        ss << "    else" << endl;
        ss << "      return 1;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int ifac(int n) { return ifac2f(1,n); }" << endl;
        ss << "" << endl;
        ss << "int ifac2f(int l, int h) {" << endl;
        ss << "        if (l == h)" << endl;
        ss << "          return l;" << endl;
        ss << "        if (l > h)" << endl;
        ss << "          return 1;" << endl;
        ss << "        int m;" << endl;
        ss << "        m = (l + h) / 2;" << endl;
        ss << "        return ifac2f(l,m) * ifac2f(m+1,h);" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "string repStr(string s, int n) {" << endl;
        ss << "  string r = \"\";" << endl;
        ss << "  int i = 0;" << endl;
        ss << "  while(i<n) {" << endl;
        ss << "    r = r + s;" << endl;
        ss << "    i++;" << endl;
        ss << "  }" << endl;
        ss << " return r;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << (long long) 3628800 << endl;
        ss << (long long) 3628800 << endl;
        ss << (long long) 3628800 << endl;
        ss << (long long) 3628800 << endl;
        ss << (long long) 3628800 << endl;
        ss << "============================================================" << endl;
        ss << "hello */" << endl;
        ss << "/* world" << endl;
    }
};

        
        
        
class MimUWTest2 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest2(): WholeProgramTestCaseUnit("MIM UW 2") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        
        ss << "/* void expression as statement */" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  foo();" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "void foo() {" << endl;
        ss << "   printString(\"foo\");" << endl;
        ss << "   return;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "foo" << endl;
    }
};
        
        
        
class MimUWTest3 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest3(): WholeProgramTestCaseUnit("MIM UW 3") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "// Testing the return checker" << endl;
        ss << "" << endl;
        ss << "int f () {" << endl;
        ss << "   if (true)" << endl;
        ss << "     return 0;" << endl;
        ss << "   else" << endl;
        ss << "     {}" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int g () {" << endl;
        ss << "  if (false) " << endl;
        ss << "      {}" << endl;
        ss << "  else" << endl;
        ss << "      return 0;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "void p () {}" << endl;
        ss << "  " << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  p();" << endl;
        ss << "  return 0;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
    }
};
      
        
class MimUWTest4 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest4(): WholeProgramTestCaseUnit("MIM UW 4") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* allow comparing booleans. */" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  if (true == true) { printInt(42); }" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 42 << endl;
    }
};


class MimUWTest5 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest5(): WholeProgramTestCaseUnit("MIM UW 5") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* usage of variable initialized in both branches. */" << endl;
        ss << "" << endl;
        ss << "int main () {" << endl;
        ss << "  int x;" << endl;
        ss << "  int y = 56;" << endl;
        ss << "  if (y + 45 <= 2) {" << endl;
        ss << "    x = 1;" << endl;
        ss << "  } else {" << endl;
        ss << "    x = 2;" << endl;
        ss << "  }" << endl;
        ss << "  printInt(x);" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 2 << endl;
    }
};
     
        
class MimUWTest6 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest6(): WholeProgramTestCaseUnit("MIM UW 6") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "// Declaration of multiple variables of the same type in one statement:" << endl;
        ss << "" << endl;
        ss << "int main () {" << endl;
        ss << "  int x, y;" << endl;
        ss << "  x = 45;" << endl;
        ss << "  y = -36;" << endl;
        ss << "  printInt(x);" << endl;
        ss << "  printInt(y);" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 45 << endl;
        ss << -36 << endl;
    }
};
        
        
class MimUWTest7 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest7(): WholeProgramTestCaseUnit("MIM UW 7") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "// declaration and initialization in same statement" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << " int x = 7;" << endl;
        ss << " printInt(x);" << endl;
        ss << " return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 7 << endl;
    }
};

        
class MimUWTest8 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest8(): WholeProgramTestCaseUnit("MIM UW 8") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "// multiple variables of the same type declared " << endl;
        ss << "// and possibly initialized in the same statement" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << " int x, y = 7;" << endl;
        ss << " x = -1234234;" << endl;
        ss << " printInt(x);" << endl;
        ss << " printInt(y);" << endl;
        ss << " return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << -1234234 << endl;
        ss << 7 << endl;
    }
};
        

class MimUWTest9 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest9(): WholeProgramTestCaseUnit("MIM UW 9") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "// Calling functions which take zero parameters" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << " int x = foo();" << endl;
        ss << " printInt(x);" << endl;
        ss << " return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int foo() {" << endl;
        ss << " return 10;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 10 << endl;
    }
};
        

class MimUWTest10 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest10(): WholeProgramTestCaseUnit("MIM UW 10") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "// count function parameters as initialized" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  printInt(fac(5));" << endl;
        ss << "  return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int fac (int a) {" << endl;
        ss << "  int r;" << endl;
        ss << "  int n;" << endl;
        ss << "  r = 1;" << endl;
        ss << "  n = a;" << endl;
        ss << "  while (n > 0)" << endl;
        ss << "  {" << endl;
        ss << "    r = r * n;" << endl;
        ss << "    n = n - 1;" << endl;
        ss << "  }" << endl;
        ss << "  return r;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 120 << endl;
    }
};
        

class MimUWTest11 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest11(): WholeProgramTestCaseUnit("MIM UW 11") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* Test pushing -1. */" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  printInt(-1);" << endl;
        ss << "  return 0 ;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << -1 << endl;
    }
};
        

class MimUWTest12 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest12(): WholeProgramTestCaseUnit("MIM UW 12") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* Test arithmetic and comparisons. */" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "    int x = 56;" << endl;
        ss << "    int y = -23;" << endl;
        ss << "    printInt(x+y);" << endl;
        ss << "    printInt(x-y);" << endl;
        ss << "    printInt(x*y);" << endl;
        ss << "    printInt(45/2);" << endl;
        ss << "    printInt(78%3);" << endl;
        ss << "    printBool(x-y > x+y);" << endl;
        ss << "    printBool(x/y <= x*y);" << endl;
        ss << "    printString(\"string\"+\" \"+\"concatenation\");" << endl;
        ss << "    return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "void printBool(boolean b) {" << endl;
        ss << "  if (b) {" << endl;
        ss << "    printString(\"true\");" << endl;
        ss << "    return;" << endl;
        ss << "  } else {" << endl;
        ss << "    printString(\"false\");" << endl;
        ss << "    return;" << endl;
        ss << " }" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 33 << endl;
        ss << 79 << endl;
        ss << -1288 << endl;
        ss << 22 << endl;
        ss << 0 << endl;
        ss << "true" << endl;
        ss << "false" << endl;
        ss << "string concatenation" << endl;
    }
};
        
   
class MimUWTest13 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest13(): WholeProgramTestCaseUnit("MIM UW 13") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* Test boolean operators. */" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  printString(\"&&\");" << endl;
        ss << "  printBool(test(-1) && test(0));" << endl;
        ss << "  printBool(test(-2) && test(1));" << endl;
        ss << "  printBool(test(3) && test(-5));" << endl;
        ss << "  printBool(test(234234) && test(21321));" << endl;
        ss << "  printString(\"||\");" << endl;
        ss << "  printBool(test(-1) || test(0));" << endl;
        ss << "  printBool(test(-2) || test(1));" << endl;
        ss << "  printBool(test(3) || test(-5));" << endl;
        ss << "  printBool(test(234234) || test(21321));" << endl;
        ss << "  printString(\"!\");" << endl;
        ss << "  printBool(true);" << endl;
        ss << "  printBool(false);" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "void printBool(boolean b) {" << endl;
        ss << "  if (!b) {" << endl;
        ss << "    printString(\"false\");" << endl;
        ss << "  } else {" << endl;
        ss << "    printString(\"true\");" << endl;
        ss << " }" << endl;
        ss << " return;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "boolean test(int i) {" << endl;
        ss << "  printInt(i);" << endl;
        ss << "  return i > 0;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "&&" << endl;
        ss << -1 << endl;
        ss << "false" << endl;
        ss << -2 << endl;
        ss << "false" << endl;
        ss << 3 << endl;
        ss << -5 << endl;
        ss << "false" << endl;
        ss << 234234 << endl;
        ss << 21321 << endl;
        ss << "true" << endl;
        ss << "||" << endl;
        ss << -1 << endl;
        ss << 0 << endl;
        ss << "false" << endl;
        ss << -2 << endl;
        ss << 1 << endl;
        ss << "true" << endl;
        ss << 3 << endl;
        ss << "true" << endl;
        ss << 234234 << endl;
        ss << "true" << endl;
        ss << "!" << endl;
        ss << "true" << endl;
        ss << "false" << endl;

    }
};
        
class MimUWTest14 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest14(): WholeProgramTestCaseUnit("MIM UW 14") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* Fibonacci. */" << endl;
        ss << "" << endl;
        ss << "int main () {" << endl;
        ss << "  int lo,hi,mx ;" << endl;
        ss << "  lo = 1 ;" << endl;
        ss << "  hi = lo ;" << endl;
        ss << "  mx = 5000000 ;" << endl;
        ss << "  printInt(lo) ;" << endl;
        ss << "  while (hi < mx) {" << endl;
        ss << "    printInt(hi) ;" << endl;
        ss << "    hi = lo + hi ;" << endl;
        ss << "    lo = hi - lo ;" << endl;
        ss << "  }" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1<< endl;
        ss << 1<< endl;
        ss << 2<< endl;
        ss << 3<< endl;
        ss << 5<< endl;
        ss << 8<< endl;
        ss << 13<< endl;
        ss << 21<< endl;
        ss << 34<< endl;
        ss << 55<< endl;
        ss << 89<< endl;
        ss << 144<< endl;
        ss << 233<< endl;
        ss << 377<< endl;
        ss << 610<< endl;
        ss << 987<< endl;
        ss << 1597<< endl;
        ss << 2584<< endl;
        ss << 4181<< endl;
        ss << 6765<< endl;
        ss << 10946<< endl;
        ss << 17711<< endl;
        ss << 28657<< endl;
        ss << 46368<< endl;
        ss << 75025<< endl;
        ss << 121393<< endl;
        ss << 196418<< endl;
        ss << 317811<< endl;
        ss << 514229<< endl;
        ss << 832040<< endl;
        ss << 1346269<< endl;
        ss << 2178309<< endl;
        ss << 3524578<< endl;
    }
};

        
class MimUWTest15 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest15(): WholeProgramTestCaseUnit("MIM UW 15") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* parity of positive integers by recursion */" << endl;
        ss << "" << endl;
        ss << "int main () {" << endl;
        ss << "  printInt(ev(17)) ;" << endl;
        ss << "  return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int ev (int y) {" << endl;
        ss << "  if (y > 0)" << endl;
        ss << "    return ev (y-2) ;" << endl;
        ss << "  else" << endl;
        ss << "    if (y < 0)" << endl;
        ss << "      return 0 ;" << endl;
        ss << "    else" << endl;
        ss << "      return 1 ;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 0 << endl;
    }
};
     
        
class MimUWTest16 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest16(): WholeProgramTestCaseUnit("MIM UW 16") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* parity of positive integers by loop */" << endl;
        ss << "" << endl;
        ss << "int main () {" << endl;
        ss << "  int y = 17;" << endl;
        ss << "  while (y > 0)" << endl;
        ss << "    y = y - 2;" << endl;
        ss << "  if (y < 0) {" << endl;
        ss << "    printInt(0);" << endl;
        ss << "    return 0 ;" << endl;
        ss << "    }" << endl;
        ss << "  else {" << endl;
        ss << "    printInt(1);" << endl;
        ss << "    return 0 ;" << endl;
        ss << "    }" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 0 << endl;
    }
};
        
        
class MimUWTest17 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest17(): WholeProgramTestCaseUnit("MIM UW 17") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* Test boolean operators */" << endl;
        ss << "" << endl;
        ss << "int main () {" << endl;
        ss << "  int x = 4;" << endl;
        ss << "  if (3 <= x && 4 != 2 && true) {" << endl;
        ss << "    printBool(true);" << endl;
        ss << "  } else {" << endl;
        ss << "    printString(\"apa\");" << endl;
        ss << "  }" << endl;
        ss << "" << endl;
        ss << "  printBool(true == true || dontCallMe(1));" << endl;
        ss << "  printBool(4 < -5 && dontCallMe(2));" << endl;
        ss << "" << endl;
        ss << "  printBool(4 == x && true == !false && true);" << endl;
        ss << "" << endl;
        ss << "  printBool(implies(false,false));" << endl;
        ss << "  printBool(implies(false,true));" << endl;
        ss << "  printBool(implies(true,false));" << endl;
        ss << "  printBool(implies(true,true));" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "boolean dontCallMe(int x) {" << endl;
        ss << "  printInt(x);" << endl;
        ss << "  return true;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "void printBool(boolean b) {" << endl;
        ss << "  if (b) {" << endl;
        ss << "    printString(\"true\");" << endl;
        ss << "  } else {" << endl;
        ss << "    printString(\"false\");" << endl;
        ss << " }" << endl;
        ss << " return;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "boolean implies(boolean x, boolean y) {" << endl;
        ss << "  return !x || x == y;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "true" << endl;
        ss << "true" << endl;
        ss << "false" << endl;
        ss << "true" << endl;
        ss << "true" << endl;
        ss << "true" << endl;
        ss << "false" << endl;
        ss << "true" << endl;
    }
};
        

class MimUWTest18 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest18(): WholeProgramTestCaseUnit("MIM UW 18") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "/* test input */" << endl;
        ss << "" << endl;
        ss << "int main() {" << endl;
        ss << "  int x = readInt();" << endl;
        ss << "  string y = readString();" << endl;
        ss << "  string z = readString();" << endl;
        ss << "" << endl;
        ss << "  printInt(x-5);" << endl;
        ss << "  printString(y+z);  " << endl;
        ss << "  return 0 ;" << endl;
        ss << "}" << endl;
    }
        
    void fillInput(std::ostream & ss) const noexcept override {
        ss << -37 << endl;
        ss << "foo" << endl;
        ss << "bar" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << -42 << endl;
        ss << "foobar" << endl;
    }
};

        
        
class MimUWTest19 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest19(): WholeProgramTestCaseUnit("MIM UW 19") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "  int i = 78;" << endl;
        ss << "  {" << endl;
        ss << "    int i = 1;" << endl;
        ss << "    printInt(i);" << endl;
        ss << "  }" << endl;
        ss << "  printInt(i);" << endl;
        ss << "  while (i > 76) {" << endl;
        ss << "    i--;" << endl;
        ss << "    printInt(i);" << endl;
        ss << "   // this is a little tricky" << endl;
        ss << "   // on the right hand side, i refers to the outer i" << endl;
        ss << "   int i = i + 7;" << endl;
        ss << "   printInt(i);" << endl;
        ss << "  }" << endl;
        ss << "  printInt(i);" << endl;
        ss << "  if (i > 4) {" << endl;
        ss << "    int i = 4;" << endl;
        ss << "    printInt(i);" << endl;
        ss << "  } else {" << endl;
        ss << "    printString(\"foo\");" << endl;
        ss << "  } " << endl;
        ss << "  printInt(i);" << endl;
        ss << "  return 0 ;" << endl;
        ss << "" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
        ss << 78 << endl;
        ss << 77 << endl;
        ss << 84 << endl;
        ss << 76 << endl;
        ss << 83 << endl;
        ss << 76 << endl;
        ss << 4 << endl;
        ss << 76 << endl;
    }
};
        
        
class MimUWTest20 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest20(): WholeProgramTestCaseUnit("MIM UW 20") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    p();" << endl;
        ss << "    printInt(1);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "void p() {}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
    }
};
     
        
        
class MimUWTest21 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest21(): WholeProgramTestCaseUnit("MIM UW 21") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    if (true) {" << endl;
        ss << "      printInt(1);" << endl;
        ss << "      return 0;" << endl;
        ss << "    }" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
    }
};
        

class MimUWTest22 final: public WholeProgramTestCaseUnit {
public:
    MimUWTest22(): WholeProgramTestCaseUnit("MIM UW 22") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int x;" << endl;
        ss << "    printInt(x);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 0 << endl;
    }
};
        
        
vector<shared_ptr<TestUnit> > MimUWTests::getTests() const noexcept {
    return {
        make_shared<MimUWTest1>(),
        make_shared<MimUWTest2>(),
        make_shared<MimUWTest3>(),
        make_shared<MimUWTest4>(),
        make_shared<MimUWTest5>(),
        make_shared<MimUWTest6>(),
        make_shared<MimUWTest7>(),
        make_shared<MimUWTest8>(),
        make_shared<MimUWTest9>(),
        make_shared<MimUWTest10>(),
        make_shared<MimUWTest11>(),
        make_shared<MimUWTest12>(),
        make_shared<MimUWTest13>(),
        make_shared<MimUWTest14>(),
        make_shared<MimUWTest15>(),
        make_shared<MimUWTest16>(),
        make_shared<MimUWTest17>(),
        make_shared<MimUWTest18>(),
        make_shared<MimUWTest19>(),
        make_shared<MimUWTest20>(),
        make_shared<MimUWTest21>(),
        make_shared<MimUWTest22>()
    };
}
