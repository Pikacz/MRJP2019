//
//  ExprCall.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprCall_hpp
#define ExprCall_hpp

#include "Expression.hpp"
#include <memory>
#include <vector>


#include "../../environment/Environment.hpp"

class ExprCall final: public Expression {
public:
    ExprCall(
        size_t line,
        size_t column,
        Environment * env,
        std::unique_ptr<const Expression> func,
        std::vector<std::unique_ptr<const Expression>> params
    ) noexcept(false);
    
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
    
    
private:
    const std::unique_ptr<const Expression> func;
    const std::vector<std::unique_ptr<const Expression>> params;
};

#endif /* ExprCall_hpp */
