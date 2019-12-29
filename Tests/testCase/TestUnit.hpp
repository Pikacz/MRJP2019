//
//  TestUnit.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef TestUnit_hpp
#define TestUnit_hpp

#include <stdio.h>
#include <string>

class TestUnit {
public:
    TestUnit(std::string name) noexcept;
    
    std::string getName() const noexcept;
    
    virtual void run() noexcept = 0;
protected:
    void assertTrue(bool expr);
    
    void assertFalse(bool expr);
private:
    const std::string name;
};

#endif /* TestUnit_hpp */
