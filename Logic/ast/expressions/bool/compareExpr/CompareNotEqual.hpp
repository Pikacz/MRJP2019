//
//  CompareNotEqual.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CompareNotEqual_hpp
#define CompareNotEqual_hpp

#include "CompareExpr.hpp"

class CompareNotEqual final: public CompareExpr {
public:
    CompareNotEqual(
        Environment const * env,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs
    );
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
protected:
    virtual std::unique_ptr<const AsmInstruction> getJump(
        AsmLabel const * lblTrue
    ) const noexcept override;
};

#endif /* CompareNotEqual_hpp */
