//
//  MainReturnValueTestCaseUnit.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef MainReturnValueTestCaseUnit_hpp
#define MainReturnValueTestCaseUnit_hpp

#include "Logic.hpp"
#include "../../../testCase/TestUnit.hpp"


class MainReturnValueTestCaseUnit: public TestUnit {
public:
    using TestUnit::TestUnit;
    
    
    void run() noexcept override;
protected:
    virtual void fillEnv(GlobalEnvironment & gEnv) const noexcept = 0;
    
    virtual int expectedExitCode() const noexcept = 0;
};



#endif /* MainReturnValueTestCaseUnit_hpp */
