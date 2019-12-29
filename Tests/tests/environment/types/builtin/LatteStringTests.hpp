//
//  LateStringTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef LateStringTests_hpp
#define LateStringTests_hpp

#include <stdio.h>
#include "../../../../testCase/TestCase.hpp"

class LatteStringTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* LateStringTests_hpp */
