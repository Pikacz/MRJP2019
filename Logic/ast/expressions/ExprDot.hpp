//
//  ExprDot.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprDot_hpp
#define ExprDot_hpp

#include "Expression.hpp"
#include <memory>


class ExprDot final: public Expression {
public:
    ExprDot(
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs
    ) noexcept;
    
    virtual bool isTerminating() const noexcept override;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
    size_t fakeVariablesCount() const noexcept override;
    
protected:
    const std::unique_ptr<const Expression> lhs;
    const std::unique_ptr<const Expression> rhs;
};

#endif /* ExprDot_hpp */
