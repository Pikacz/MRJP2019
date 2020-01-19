//
//  ParserTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ParserTests.hpp"
#include "MainReturnParserTestCaseUnit.hpp"

#include <memory>
#include <vector>

using namespace std;


class ParseT1 final: public MainReturnParserTestCaseUnit {
public:
    ParseT1(): MainReturnParserTestCaseUnit("ParseT1") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    return 0;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 0;
    }
};


class ParseT2 final: public MainReturnParserTestCaseUnit {
public:
    ParseT2(): MainReturnParserTestCaseUnit("ParseT2") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int a = 2;" << endl;
        ss << "    return a;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 2;
    }
};


        
class ParseT3 final: public MainReturnParserTestCaseUnit {
public:
    ParseT3(): MainReturnParserTestCaseUnit("ParseT3") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int a = 2;" << endl;
        ss << "    a++;" << endl;
        ss << "    return a;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 3;
    }
};

class ParseT4 final: public MainReturnParserTestCaseUnit {
public:
    ParseT4(): MainReturnParserTestCaseUnit("ParseT4") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    int a = 2;" << endl;
        ss << "    a--;" << endl;
        ss << "    return a;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 1;
    }
};

class ParseT5 final: public MainReturnParserTestCaseUnit {
public:
    ParseT5(): MainReturnParserTestCaseUnit("ParseT5") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    return 8 - 2 * 3;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 2;
    }
};


class ParseT6 final: public MainReturnParserTestCaseUnit {
public:
    ParseT6(): MainReturnParserTestCaseUnit("ParseT6") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    return (8 - 2) * 3;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 18;
    }
};

class ParseT7 final: public MainReturnParserTestCaseUnit {
public:
    ParseT7(): MainReturnParserTestCaseUnit("ParseT7") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    return 78 % 3;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 0;
    }
};
        
class ParseT8 final: public MainReturnParserTestCaseUnit {
public:
    ParseT8(): MainReturnParserTestCaseUnit("ParseT8") {}
    
    void fillCode(std::stringstream &ss) const noexcept override {
        ss << "int main() {" << endl;
        ss << "    return 78%3;" << endl;
        ss << "}" << endl;
    }
    
    int expectedExitCode() const noexcept override {
        return 0;
    }
};

vector<shared_ptr<TestUnit> > ParserTests::getTests() const noexcept {
    return {
        make_shared<ParseT1>(),
        make_shared<ParseT2>(),
        make_shared<ParseT3>(),
        make_shared<ParseT4>(),
        make_shared<ParseT5>(),
        make_shared<ParseT6>(),
        make_shared<ParseT7>(),
        make_shared<ParseT8>(),
    };
}
