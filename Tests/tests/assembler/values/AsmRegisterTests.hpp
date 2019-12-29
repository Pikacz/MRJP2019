//
//  AsmRegisterTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmRegisterTests_hpp
#define AsmRegisterTests_hpp

#include <stdio.h>
#include "../../../testCase/TestCase.hpp"

class AsmRegisterTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* AsmRegisterTests_hpp */
