//
//  ExprNewObject.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprNewObject_hpp
#define ExprNewObject_hpp


#include "Expression.hpp"
#include "../../environment/types/custom/CustomType.hpp"


#include <memory>

class ExprNewObject final: public Expression {
public:
    
    ExprNewObject(Type const * type, size_t line, size_t column) noexcept(false);
    
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
    const CustomType * const objType;
};


#endif /* ExprNewObject_hpp */
