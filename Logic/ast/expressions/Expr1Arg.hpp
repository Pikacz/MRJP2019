//
//  Expr1Arg.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef Expr1Arg_hpp
#define Expr1Arg_hpp

#include "Expression.hpp"
#include <memory>


class Expr1Arg: public Expression {
public:
    Expr1Arg(
        Type const * type,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> expr
    ) noexcept;
    
    size_t fakeVariablesCount() const noexcept override;
protected:
    const std::unique_ptr<const Expression> expr;
};

#endif /* Expr1Arg_hpp */
