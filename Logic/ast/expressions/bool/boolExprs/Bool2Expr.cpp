//
//  BoolOrExpr.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "Bool2Expr.hpp"

#include "../../../../staticCheck/types/InvalidType.hpp"

using namespace std;

Bool2Expr::Bool2Expr(
    Environment const * env,
    size_t line,
    size_t column,
    unique_ptr<const Expression> _lhs,
    unique_ptr<const Expression> _rhs
) noexcept(false): Expr2Arg(env->getLatteBool(), line, column, move(_lhs), move(_rhs)) {
    auto lType = this->lhs.get()->getType();
    if (!lType->isKindOf(env->getLatteBool())) {
        throw InvalidType(
            this->lhs.get()->getLine(),
            this->lhs.get()->getColumn(),
            env->getLatteBool(),
            lType
        );
    }
    
    
    auto rType = this->rhs.get()->getType();
    if (!rType->isKindOf(env->getLatteBool())) {
        throw InvalidType(
            this->rhs.get()->getLine(),
            this->rhs.get()->getColumn(),
            env->getLatteBool(),
            rType
        );
    }
}
