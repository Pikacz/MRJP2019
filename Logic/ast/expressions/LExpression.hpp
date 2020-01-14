//
//  LExpression.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef LExpression_hpp
#define LExpression_hpp

#include "Expression.hpp"

class LExpression: public Expression {
public:
    using Expression::Expression;
    
    virtual void saveValueFrom(
        AsmRegister::Type source,
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept;
    
    
    virtual void loadValueInto(
        AsmRegister::Type destination,
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept;
    
    virtual std::unique_ptr<const AssemblerValue> getAddress(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler
    ) const noexcept = 0;
};

#endif /* LExpression_hpp */
