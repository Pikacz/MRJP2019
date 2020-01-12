//
//  VariableExpression.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 06/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef VariableExpression_hpp
#define VariableExpression_hpp

#include "../../../testCase/TestCase.hpp"


class VariableExpression final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};


#endif /* VariableExpression_hpp */
