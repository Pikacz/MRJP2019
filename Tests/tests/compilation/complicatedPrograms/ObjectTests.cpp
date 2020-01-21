//
//  ObjectTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ObjectTests.hpp"
#include "WholeProgramTestCaseUnit.hpp"

#include <memory>
#include <vector>
using namespace std;

class ObjectTest1 final: public WholeProgramTestCaseUnit {
public:
    ObjectTest1(): WholeProgramTestCaseUnit("Object Test 1") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "class A { }" << endl;
        ss << "int main() {" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
    }
};
        
class ObjectTest2 final: public WholeProgramTestCaseUnit {
public:
    ObjectTest2(): WholeProgramTestCaseUnit("Object Test 1") {}
    
    void fillCode(std::ostream & ss) const noexcept override {
        ss << "class A {" << endl;
        ss << "    int i;" << endl;
        ss << "}" << endl;
        ss << "int main() {" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
        ss << "" << endl;
    }
    
    void fillOutput(std::ostream & ss) const noexcept override {
    }
};

vector<shared_ptr<TestUnit> > ObjectTests::getTests() const noexcept {
    return {
        make_shared<ObjectTest1>(),
        make_shared<ObjectTest2>()
    };
}
