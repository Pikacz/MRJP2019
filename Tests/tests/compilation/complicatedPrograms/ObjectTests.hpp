//
//  ObjectTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ObjectTests_hpp
#define ObjectTests_hpp

#include "../../../testCase/TestCase.hpp"


class ObjectTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};
#endif /* ObjectTests_hpp */
