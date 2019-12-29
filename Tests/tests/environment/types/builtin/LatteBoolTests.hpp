//
//  LatteBoolTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef LatteBoolTests_hpp
#define LatteBoolTests_hpp

#include "../../../../testCase/TestCase.hpp"

class LatteBoolTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* LatteBoolTests_hpp */
