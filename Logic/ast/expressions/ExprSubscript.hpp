//
//  ExprSubscript.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprSubscript_hpp
#define ExprSubscript_hpp

#include <stdio.h>

#include "Expression.hpp"

class ExprSubscript final: public Expression {
public:
    ExprSubscript(
        size_t line,
        size_t column,
        Environment * env,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> expr
    ) noexcept(false);
    
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
    
protected:
    const std::unique_ptr<const Expression> lhs;
    const std::unique_ptr<const Expression> expr;
};

#endif /* ExprSubscript_hpp */
