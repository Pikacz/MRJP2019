//
//  TestCase.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef TestCase_hpp
#define TestCase_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include <string>

#include "TestUnit.hpp"

class TestCase {
public:
    TestCase(std::string name) noexcept;
    
    std::string getName() const noexcept;
    
    void run(std::string prefix) const noexcept;
protected:
    virtual std::vector<std::shared_ptr<TestUnit>> getTests()
        const noexcept = 0;
private:
    const std::string name;
};

#endif /* TestCase_hpp */
