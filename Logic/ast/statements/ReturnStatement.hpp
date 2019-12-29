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

class ReturnStatement final: public Statement {
    
public:
    ReturnStatement(std::optional<std::unique_ptr<const Expression>> expr = std::nullopt) noexcept;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    bool isTerminatingWith(Type const * type) const noexcept(false) override;
private:
    std::optional<std::unique_ptr<const Expression>> expr;
};

#endif /* ReturnStatement_hpp */
