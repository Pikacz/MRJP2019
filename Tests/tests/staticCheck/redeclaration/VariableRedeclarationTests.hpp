//
//  VariableRedeclarationTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef VariableRedeclarationTests_hpp
#define VariableRedeclarationTests_hpp

#include <stdio.h>
#include "../../../testCase/TestCase.hpp"

class VariableRedeclarationTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};

#endif /* VariableRedeclarationTests_hpp */
