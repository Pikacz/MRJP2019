//
//  SimpleProgramsTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef SimpleProgramsTests_hpp
#define SimpleProgramsTests_hpp

#include "../../../testCase/TestCase.hpp"


class SimpleProgramsTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* SimpleProgramsTests_hpp */
