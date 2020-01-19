//
//  CompareExpr.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CompareExpr_hpp
#define CompareExpr_hpp

#include "../../Expr2Arg.hpp"
#include "../../../../environment/Environment.hpp"

class CompareExpr: public Expr2Arg {
public:
    CompareExpr(
        Environment const * env,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs,
        bool allowBool = false
    ) noexcept(false);
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;

protected:
    virtual std::unique_ptr<const AsmInstruction> getJump(
        AsmLabel const * lblTrue
    ) const noexcept = 0;
};

#endif /* CompareExpr_hpp */
