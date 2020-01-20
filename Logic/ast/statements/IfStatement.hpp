//
//  IfStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 07/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef IfStatement_hpp
#define IfStatement_hpp

#include "Statement.hpp"
#include "../expressions/Expression.hpp"

#include "../../environment/Environment.hpp"

#include <memory>

class IfStatement final: public Statement {
public:
    IfStatement(
        size_t line,
        size_t column,
        Environment const * env,
        std::unique_ptr<const Expression> expr,
        std::unique_ptr<const Statement> ifTrue,
        std::unique_ptr<const Statement> ifFalse
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
    const std::unique_ptr<const Statement> ifTrue;
    const std::unique_ptr<const Statement> ifFalse;
};

#endif /* IfStatement_hpp */
