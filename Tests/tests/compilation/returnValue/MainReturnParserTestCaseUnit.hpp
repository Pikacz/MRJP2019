//
//  MainReturnParserTestCase.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef MainReturnParserTestCaseUnit_hpp
#define MainReturnParserTestCaseUnit_hpp

#include "MainReturnValueTestCaseUnit.hpp"

#include <sstream>

class MainReturnParserTestCaseUnit: public TestUnit {
public:
    using TestUnit::TestUnit;

    
    void run() noexcept override;
protected:
    
    virtual void fillCode(std::stringstream & ss) const noexcept = 0;
    
    virtual int expectedExitCode() const noexcept = 0;
};

#endif /* MainReturnParserTestCaseUnit_hpp */
