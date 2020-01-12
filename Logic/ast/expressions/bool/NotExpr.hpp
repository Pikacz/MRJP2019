//
//  NotExpr.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef NotExpr_hpp
#define NotExpr_hpp

#include "../Expr1Arg.hpp"
#include "../../../environment/Environment.hpp"
#include <memory>

class NotExpr final: public Expr1Arg {
public:
    NotExpr(
        Environment const * env,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> expr
    ) noexcept(false);
    
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

#endif /* NotExpr_hpp */
