//
//  NoSuchTypeErrorTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "NoSuchTypeErrorTests.hpp"
#include "../../../testCase/units/TestMessageContainsInformation.hpp"
#include "Logic.hpp"
#include <memory>
#include <string>


using namespace std;

vector<shared_ptr<TestUnit>> NoSuchTypeErrorTests::getTests()
const noexcept {
    
    string n1 = "Error message test";
    string m1 = NoSuchTypeError(1, 1, "placki").what();
    vector<string> texts1 = { "1", "1", "placki" };
    shared_ptr<TestUnit> t1 = make_shared<TestMessageContainsInformation>(
        n1, m1, texts1
    );
    
    string n2 = "Error message test 2";
    string m2 = NoSuchTypeError(23, 45, "placki").what();
    vector<string> texts2 = { "23", "45", "placki" };
    shared_ptr<TestUnit> t2 = make_shared<TestMessageContainsInformation>(
        n2, m2, texts2
    );
    
    return {
        t1, t2
    };
}
