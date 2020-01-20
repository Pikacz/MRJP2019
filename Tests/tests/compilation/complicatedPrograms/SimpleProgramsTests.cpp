//
//  SimpleProgramsTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "SimpleProgramsTests.hpp"
#include "WholeProgramTestCaseUnit.hpp"

#include <memory>
#include <vector>

using namespace std;

class SimpleProgram1 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram1(): WholeProgramTestCaseUnit("Simple program 1") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(1);" << endl;
        ss << "    return 1;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
    }
        
    int expectedExitCode() const noexcept override {
        return 1;
    }
};


class SimpleProgram2 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram2(): WholeProgramTestCaseUnit("Simple program 2") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    test(1);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "void test(int i) {" << endl;
        ss << "    printInt(i);" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
    }
};
       
class SimpleProgram3 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram3(): WholeProgramTestCaseUnit("Simple program 3") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printString(\"hehe liczysz ze to zadziala\");" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "hehe liczysz ze to zadziala" << endl;
    }
};
        
class SimpleProgram4 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram4(): WholeProgramTestCaseUnit("Simple program 4") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int a;" << endl;
        ss << "    a = readInt();" << endl;
        ss << "    printInt(a);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
        
    void fillInput(std::ostream & ss) const noexcept override {
        ss << 13 << endl;
    }
        
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 13 << endl;
    }
};
        
        
class SimpleProgram5 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram5(): WholeProgramTestCaseUnit("Simple program 5") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(readInt());" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
        
    void fillInput(std::ostream & ss) const noexcept override {
        ss << 13 << endl;
    }
        
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 13 << endl;
    }
};

class SimpleProgram6 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram6(): WholeProgramTestCaseUnit("Simple program 6") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int a;" << endl;
        ss << "    a = readInt();" << endl;
        ss << "    printInt(1 + a * 4 - 17);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
        
    void fillInput(std::ostream & ss) const noexcept override {
        ss << 13 << endl;
    }
        
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 + 13 * 4 - 17 << endl;
    }
};
        
        
class SimpleProgram7 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram7(): WholeProgramTestCaseUnit("Simple program 7") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(1 + readInt() * 4 - 17);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
        
    void fillInput(std::ostream & ss) const noexcept override {
        ss << 13 << endl;
    }
        
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 + 13 * 4 - 17 << endl;
    }
};

class SimpleProgram8 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram8(): WholeProgramTestCaseUnit("Simple program 8") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int r;" << endl;
        ss << "    int n;" << endl;
        ss << "" << endl;
        ss << "    r = 1;" << endl;
        ss << "    n = 10;" << endl;
        ss << "    while (n > 0) {" << endl;
        ss << "      r = r * n;" << endl;
        ss << "      n = n - 1;" << endl;
        ss << "    }" << endl;
        ss << "    printInt(r);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 3628800 << endl;
    }
};

        
class SimpleProgram9 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram9(): WholeProgramTestCaseUnit("Simple program 9") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    fac(10);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "void fac(int a) {" << endl;
        ss << "    printInt(a);" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 10 << endl;
    }
};
        

class SimpleProgram10 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram10(): WholeProgramTestCaseUnit("Simple program 10") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    fac(10);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "void fac(int a) {" << endl;
        ss << "    int n;" << endl;
        ss << "    n = a;" << endl;
        ss << "    printInt(a);" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 10 << endl;
    }
};
        
class SimpleProgram11 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram11(): WholeProgramTestCaseUnit("Simple program 11") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int x = fac(10);" << endl;
        ss << "    printInt(x);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
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
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 3628800 << endl;
    }
};
        
        
class SimpleProgram12 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram12(): WholeProgramTestCaseUnit("Simple program 12") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(fac(20));" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "int fac(int a) {" << endl;
        ss << "    return a;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 20 << endl;
    }
};
        
        
class SimpleProgram13 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram13(): WholeProgramTestCaseUnit("Simple program 13") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(fac(20));" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
        ss << "int fac(int a) {" << endl;
        ss << "    int n;" << endl;
        ss << "    n = a;" << endl;
        ss << "    return n;" << endl;
        ss << "}" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 20 << endl;
    }
};
        
class SimpleProgram14 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram14(): WholeProgramTestCaseUnit("Simple program 14") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(fac(10));" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
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
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 3628800 << endl;
    }
};
        

class SimpleProgram15 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram15(): WholeProgramTestCaseUnit("Simple program 15") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(mfac(10));" << endl;
        ss << "    return 0 ;" << endl;
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
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 3628800 << endl;
    }
};
        
       
class SimpleProgram16 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram16(): WholeProgramTestCaseUnit("Simple program 16") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(ifac(10));" << endl;
        ss << "    return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
        ss << "int ifac(int n) { return ifac2f(1,n); }" << endl;
        ss << "" << endl;
        ss << "int ifac2f(int l, int h) {" << endl;
        ss << "    return l + h;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 11 << endl;
    }
};
     
        
class SimpleProgram17 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram17(): WholeProgramTestCaseUnit("Simple program 17") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(3 / 2);" << endl;
        ss << "    return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
    }
};
        

class SimpleProgram18 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram18(): WholeProgramTestCaseUnit("Simple program 18") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt((1 + 2) / 2);" << endl;
        ss << "    return 0 ;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 1 << endl;
    }
};
        
        
class SimpleProgram19 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram19(): WholeProgramTestCaseUnit("Simple program 19") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printInt(ifac(10));" << endl;
        ss << "    return 0 ;" << endl;
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
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << 3628800 << endl;
    }
};
        
        
class SimpleProgram20 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram20(): WholeProgramTestCaseUnit("Simple program 20") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printString(\"Hello\" + \" world\");" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "Hello world" << endl;
    }
};
        

class SimpleProgram21 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram21(): WholeProgramTestCaseUnit("Simple program 21") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    printString(\"a\" + \"b\" + \"c\");" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "abc" << endl;
    }
};

        
class SimpleProgram22 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram22(): WholeProgramTestCaseUnit("Simple program 22") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    string s1 = readString();" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillInput(std::ostream & ss) const noexcept override {
        ss << "ab" << endl;
    }
};
        

class SimpleProgram23 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram23(): WholeProgramTestCaseUnit("Simple program 23") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    string s1 = \"a\" + \"b\";" << endl;
        ss << "    printString(s1);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "ab" << endl;
    }
};
        

class SimpleProgram24 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram24(): WholeProgramTestCaseUnit("Simple program 24") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    string s1 = \"a\" + \"b\";" << endl;
        ss << "    printString(s1 + \"c\");" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "abc" << endl;
    }
};
      

class SimpleProgram25 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram25(): WholeProgramTestCaseUnit("Simple program 25") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    string s1 = \"a\";" << endl;
        ss << "    string s2 = \"c\";" << endl;
        ss << "    printString(s1 + s2);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "ac" << endl;
    }
};
        
        
class SimpleProgram26 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram26(): WholeProgramTestCaseUnit("Simple program 26") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    string s1 = \"a\" + \"b\";" << endl;
        ss << "    string s2 = \"c\" + \"d\";" << endl;
        ss << "    printString(s1 + s2);" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
        ss << "abcd" << endl;
    }
};
        

class SimpleProgram27 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram27(): WholeProgramTestCaseUnit("Simple program 27") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    \"a\" + \"b\";" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
    }
};
        
vector<shared_ptr<TestUnit> > SimpleProgramsTests::getTests() const noexcept {
    return {
        make_shared<SimpleProgram1>(),
        make_shared<SimpleProgram2>(),
        make_shared<SimpleProgram3>(),
        make_shared<SimpleProgram4>(),
        make_shared<SimpleProgram5>(),
        make_shared<SimpleProgram6>(),
        make_shared<SimpleProgram7>(),
        make_shared<SimpleProgram8>(),
        make_shared<SimpleProgram9>(),
        make_shared<SimpleProgram10>(),
        make_shared<SimpleProgram11>(),
        make_shared<SimpleProgram12>(),
        make_shared<SimpleProgram13>(),
        make_shared<SimpleProgram14>(),
        make_shared<SimpleProgram15>(),
        make_shared<SimpleProgram16>(),
        make_shared<SimpleProgram17>(),
        make_shared<SimpleProgram18>(),
        make_shared<SimpleProgram19>(),
        make_shared<SimpleProgram20>(),
        make_shared<SimpleProgram21>(),
        make_shared<SimpleProgram22>(),
        make_shared<SimpleProgram23>(),
        make_shared<SimpleProgram24>(),
        make_shared<SimpleProgram25>(),
        make_shared<SimpleProgram26>(),
        make_shared<SimpleProgram27>()
    };
}
