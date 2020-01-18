//
//  VarExpression.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef VarExpression_hpp
#define VarExpression_hpp

#include "LExpression.hpp"
#include "../../environment/variables/Variable.hpp"
#include "../../environment/BlockEnvironment.hpp"

#include <string>

class VarExpression final: public LExpression {
public:
    VarExpression(
        size_t line, size_t column, Variable const * var
    ) noexcept;
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
    
    void compileCall(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) const noexcept override;
    
    std::unique_ptr<const AssemblerValue> getAddress(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept override;
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    bool isLatteErrorFunc() const noexcept;
    
private:
    const Variable * const var;

};

#endif /* VarExpression_hpp */
