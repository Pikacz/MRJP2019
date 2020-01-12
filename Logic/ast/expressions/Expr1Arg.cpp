//
//  Expr1Arg.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "Expr1Arg.hpp"

using namespace std;


Expr1Arg::Expr1Arg(
    Type const * type,
    size_t line,
    size_t column,
    unique_ptr<const Expression> expr
) noexcept: expr(move(expr)), Expression(type, line, column) {
    
}
