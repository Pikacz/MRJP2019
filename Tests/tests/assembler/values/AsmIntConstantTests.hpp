//
//  AsmIntConstantTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef AsmIntConstantTests_hpp
#define AsmIntConstantTests_hpp

#include <stdio.h>
#include "../../../testCase/TestCase.hpp"

class AsmIntConstantTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};


#endif /* AsmIntConstantTests_hpp */
