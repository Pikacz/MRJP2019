//
//  ExprNewArray.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprNewArray_hpp
#define ExprNewArray_hpp

#include "Expression.hpp"


#include <memory>

class ExprNewArray final: public Expression {
public:
    
    ExprNewArray(
        Type const * type,
        Environment * env,
        std::unique_ptr<const Expression> expr,
        size_t line, size_t column) noexcept(false);
    
    virtual bool isEqualTo(AstNode const * node) const noexcept override;
    
    virtual void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept override;
    
private:
    std::unique_ptr<const Expression> expr;
    const Type * const elemType;
};


#endif /* ExprNewArray_hpp */
