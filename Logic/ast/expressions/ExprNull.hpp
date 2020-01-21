//
//  ExprNull.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprNull_hpp
#define ExprNull_hpp

#include "Expression.hpp"
#include "../../environment/types/custom/CustomType.hpp"


class ExprNull final: public Expression {
public:
    ExprNull(
        size_t line,
        size_t column,
        Type const * type
    ) noexcept(false);
    
    
    bool isEqualTo(AstNode const * node) const noexcept override;
    
    void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
    
protected:
    const CustomType * const objType;
};


#endif /* ExprNull_hpp */
