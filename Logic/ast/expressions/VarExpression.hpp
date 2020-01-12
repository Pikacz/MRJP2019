//
//  VarExpression.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef VarExpression_hpp
#define VarExpression_hpp

#include "Expression.hpp"
#include "../../environment/variables/LValue.hpp"
#include "../../environment/BlockEnvironment.hpp"

#include <string>

class VarExpression final: public Expression {
public:
    VarExpression(
        size_t line, size_t column, LValue const * var
    ) noexcept;
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
private:
    const LValue * const var;

};

#endif /* VarExpression_hpp */
