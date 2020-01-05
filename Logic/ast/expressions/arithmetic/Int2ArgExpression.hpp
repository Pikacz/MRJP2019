//
//  Int2ArgExpression.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef Int2ArgExpression_hpp
#define Int2ArgExpression_hpp

#include "Expr2Arg.hpp"
#include "../../../environment/Environment.hpp"


class Int2ArgExpression: public Expr2Arg {
public:
    Int2ArgExpression(
        Environment const * env,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs
    ) noexcept(false);
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmRegister::Type destination
    ) const noexcept override;
    
protected:
    virtual AsmRegister::Type lhsPosition(
        AsmRegister::Type destination, AsmRegistersHandler const & handler
    ) const noexcept = 0;
    
    virtual AsmRegister::Type rhsPosition(
        AsmRegister::Type destination,
        AsmRegistersHandler const & handler,
        AsmRegister::Type lPos
    ) const noexcept = 0;
    
    virtual void calculate(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler,
        AssemblerValue::Size type,
        AsmRegister::Type lPos,
        AsmRegister::Type rPos,
        AsmRegister::Type destination
    ) const noexcept = 0;
};

#endif /* Int2ArgExpression_hpp */
