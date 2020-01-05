//
//  IntSub.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 05/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef IntSub_hpp
#define IntSub_hpp

#include "Int2ArgExpression.hpp"

class IntSub final: public Int2ArgExpression {
public:
    using Int2ArgExpression::Int2ArgExpression;
    
    bool isEqualTo(AstNode const * node) const noexcept override;

protected:
    AsmRegister::Type lhsPosition(
        AsmRegister::Type destination, AsmRegistersHandler const & handler
    ) const noexcept override;
    
    AsmRegister::Type rhsPosition(
        AsmRegister::Type destination,
        AsmRegistersHandler const & handler,
        AsmRegister::Type lPos
    ) const noexcept override;
    
    void calculate(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmRegistersHandler & handler,
        AssemblerValue::Size type,
        AsmRegister::Type lPos,
        AsmRegister::Type rPos,
        AsmRegister::Type destination
    ) const noexcept override;
};


#endif /* IntSub_hpp */
