//
//  BoolOrExpr.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef BoolOrExpr_hpp
#define BoolOrExpr_hpp

#include "Bool2Expr.hpp"


class BoolOrExpr final: public Bool2Expr {
public:
    using Bool2Expr::Bool2Expr;
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
};

#endif /* BoolOrExpr_hpp */
