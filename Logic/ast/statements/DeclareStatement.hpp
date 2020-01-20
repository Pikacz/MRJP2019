//
//  DeclareStatement.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef DeclareStatement_hpp
#define DeclareStatement_hpp

#include "Statement.hpp"
#include "../../environment/BlockEnvironment.hpp"

#include <string>

class DeclareStatement final: public Statement {
public:
    DeclareStatement(
        size_t line,
        size_t column,
        BlockEnvironment * env,
        Type const * type,
        std::string varName
    ) noexcept(false);
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmLabelHandler & handler,
        AsmLabel const * exitLabel
    ) const noexcept override;
    
    size_t fakeVariablesCount() const noexcept override;
private:
    const Type * const type;
    const std::string varName;
};


#endif /* DeclareStatement_hpp */
