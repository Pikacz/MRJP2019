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
        
        
class SimpleProgram1500 final: public WholeProgramTestCaseUnit {
public:
    SimpleProgram1500(): WholeProgramTestCaseUnit("Simple program 1500") {}
    
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
        make_shared<SimpleProgram1500>()
    };
}
