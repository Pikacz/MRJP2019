//
//  SingleExpression.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef SingleExpression_hpp
#define SingleExpression_hpp

#include <stdio.h>
#include "../../../testCase/TestCase.hpp"


class SingleExpression final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};


#endif /* SingleExpression_hpp */
