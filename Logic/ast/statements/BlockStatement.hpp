//
//  BlockStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 06/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef BlockStatement_hpp
#define BlockStatement_hpp

#include "Statement.hpp"

#include "../../environment/Environment.hpp"
#include "../../environment/BlockEnvironment.hpp"

#include <memory>
#include <vector>

class BlockStatement final: public Statement {
public:
    BlockStatement(
        size_t line,
        size_t column,
        Environment const * env
    ) noexcept;
    
    BlockEnvironment * getEnvironment() const noexcept;
    
    void completeWith(
        std::vector<std::unique_ptr<const Statement>> statements
    ) noexcept;
    
    bool isTerminatingWith(Type const * type) const noexcept(false) override;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmLabelHandler & handler,
        AsmLabel const * exitLabel
    ) const noexcept override;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
private:
    bool isCompleted;
    const std::unique_ptr<BlockEnvironment> env;
    std::vector<std::unique_ptr<const Statement>> statements;
};

#endif /* BlockStatement_hpp */
