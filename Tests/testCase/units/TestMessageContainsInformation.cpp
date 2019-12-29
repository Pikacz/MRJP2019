//
//  TestMessageContainsInformation.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "TestMessageContainsInformation.hpp"

using namespace std;


TestMessageContainsInformation::TestMessageContainsInformation(
    std::string name,
    std::string message,
    std::vector<std::string> texts
) noexcept: message(message), texts(texts), TestUnit(name) {}


void TestMessageContainsInformation::run() noexcept {
    for (auto text: texts) {
        assertTrue(message.find(text) != string::npos);
    }
}
