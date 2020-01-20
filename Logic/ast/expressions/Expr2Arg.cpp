//
//  Expr2Arg.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "Expr2Arg.hpp"


using namespace std;


Expr2Arg::Expr2Arg(
    Type const * type,
    size_t line,
    size_t column,
    unique_ptr<const Expression> lhs,
    unique_ptr<const Expression> rhs
) noexcept: lhs(move(lhs)), rhs(move(rhs)), Expression(type, line, column) {
    
}


size_t Expr2Arg::fakeVariablesCount() const noexcept {
    // only call have to save values
    return max(lhs->fakeVariablesCount(), rhs->fakeVariablesCount());
}
