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
        
        
vector<shared_ptr<TestUnit> > SimpleProgramsTests::getTests() const noexcept {
    return {
        make_shared<SimpleProgram1>(),
        make_shared<SimpleProgram2>(),
        make_shared<SimpleProgram3>(),
        make_shared<SimpleProgram4>()
    };
}
