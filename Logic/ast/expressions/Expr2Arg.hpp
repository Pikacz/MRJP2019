//
//  Expr2Arg.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef Expr2Arg_hpp
#define Expr2Arg_hpp

#include "Expression.hpp"
#include <memory>


class Expr2Arg: public Expression {
public:
    Expr2Arg(
        Type const * type,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs
    ) noexcept;
    
protected:
    const std::unique_ptr<const Expression> lhs;
    const std::unique_ptr<const Expression> rhs;
};


#endif /* Expr2Arg_hpp */
