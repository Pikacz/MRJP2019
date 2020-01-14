//
//  AssignementStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef AssignementStatement_hpp
#define AssignementStatement_hpp

#include "Statement.hpp"

#include "../expressions/Expression.hpp"
#include "../../environment/Environment.hpp"
#include "../expressions/LExpression.hpp"



class AssignementStatement final: public Statement {
public:
    AssignementStatement(
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> var,
        std::unique_ptr<const Expression> expr
    ) noexcept(false);
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmLabelHandler & handler,
        AsmLabel const * exitLabel
    ) const noexcept override;
private:
    const std::unique_ptr<const LExpression> var;
    const std::unique_ptr<const Expression> expr;
};

#endif /* AssignementStatement_hpp */
