//
//  ExprStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprStatement_hpp
#define ExprStatement_hpp

#include "Statement.hpp"
#include "../expressions/Expression.hpp"

#include "../../environment/Environment.hpp"

#include <memory>

class ExprStatement final: public Statement {
public:
    ExprStatement(
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> expr
    ) noexcept(false);
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    bool isTerminatingWith(Type const * type) const noexcept(false) override;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmLabelHandler & handler,
        AsmLabel const * exitLabel
    ) const noexcept override;

private:
    const std::unique_ptr<const Expression> expr;
};

#endif /* ExprStatement_hpp */
