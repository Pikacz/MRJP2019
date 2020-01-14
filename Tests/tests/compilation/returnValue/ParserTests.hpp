//
//  ParserTests.hpp
//  Tests
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ParserTests_hpp
#define ParserTests_hpp

#include "../../../testCase/TestCase.hpp"


class ParserTests final: public TestCase {
public:
    using TestCase::TestCase;
protected:
    std::vector<std::shared_ptr<TestUnit> > getTests()
        const noexcept override;
};


#endif /* ParserTests_hpp */
