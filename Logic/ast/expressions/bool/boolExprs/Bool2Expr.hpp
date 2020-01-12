//
//  BoolOrExpr.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef Bool2Expr_hpp
#define Bool2Expr_hpp

#include "../../Expr2Arg.hpp"
#include "../../../../environment/Environment.hpp"

class Bool2Expr: public Expr2Arg {
public:
    Bool2Expr(
        Environment const * env,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs
    ) noexcept(false);
    
};

#endif /* Bool2Expr_hpp */
