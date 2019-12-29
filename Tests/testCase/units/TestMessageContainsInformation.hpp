//
//  TestMessageContainsInformation.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef TestMessageContainsInformation_hpp
#define TestMessageContainsInformation_hpp

#include <string>
#include <vector>

#include "../TestUnit.hpp"


class TestMessageContainsInformation final: public TestUnit {
public:
    TestMessageContainsInformation(
        std::string name,
        std::string message,
        std::vector<std::string> texts
    ) noexcept;
    
    void run() noexcept override;
private:
    const std::string message;
    const std::vector<std::string> texts;
};

#endif /* TestMessageContainsInformation_hpp */
