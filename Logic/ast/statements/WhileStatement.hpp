//
//  WhileStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 11/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef WhileStatement_hpp
#define WhileStatement_hpp

#include "Statement.hpp"
#include "../expressions/Expression.hpp"

#include "../../environment/Environment.hpp"

#include <memory>

class WhileStatement final: public Statement {
public:
    WhileStatement(
        size_t line,
        size_t column,
        Environment const * env,
        std::unique_ptr<const Expression> expr,
        std::unique_ptr<const Statement> body
    ) noexcept(false);
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    bool isTerminatingWith(Type const * type) const noexcept(false) override;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmLabelHandler & handler,
        AsmLabel const * exitLabel
    ) const noexcept override;
    
    size_t fakeVariablesCount() const noexcept override;
private:
    const std::unique_ptr<const Expression> expr;
    const std::unique_ptr<const Statement> body;
};


#endif /* WhileStatement_hpp */
