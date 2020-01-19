//
//  MimUWTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 18/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef MimUWTests_hpp
#define MimUWTests_hpp

#include "../../../testCase/TestCase.hpp"


class MimUWTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* MimUWTests_hpp */
