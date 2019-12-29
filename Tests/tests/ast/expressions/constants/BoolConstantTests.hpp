//
//  BoolConstantTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef BoolConstantTests_hpp
#define BoolConstantTests_hpp

#include "../../../../testCase/TestCase.hpp"

class BoolConstantTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* BoolConstantTests_hpp */
