//
//  ReturnStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef ReturnStatement_hpp
#define ReturnStatement_hpp

#include <stdio.h>
#include <optional>

#include "Statement.hpp"

#include "../expressions/Expression.hpp"
#include "../../environment/Environment.hpp"

class ReturnStatement final: public Statement {
    
public:
    ReturnStatement(
        size_t line,
        size_t column,
        Environment const * env,
        std::optional<std::unique_ptr<const Expression>> expr = std::nullopt
    ) noexcept;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    bool isTerminatingWith(Type const * type) const noexcept(false) override;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmLabelHandler & handler,
        AsmLabel const * exitLabel
    ) const noexcept override;
private:
    const std::optional<std::unique_ptr<const Expression>> expr;
    const Type * const voidType;
};

#endif /* ReturnStatement_hpp */
