//
//  AllReturnValueTests.cpp
//  Tests
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "AllReturnValueTests.hpp"
#include "SingleExpression.hpp"
#include "VariableExpression.hpp"


void runAllReturnValueTests(std::string prefix) noexcept {
    SingleExpression t1("SingleExpression");
    t1.run(prefix);
    VariableExpression t2("VariableExpression");
    t2.run(prefix);
}
