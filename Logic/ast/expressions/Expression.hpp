//
//  Expression.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include "../AstNode.hpp"
#include "../../environment/Environment.hpp"
#include "../../environment/types/Type.hpp"

#include "../../assembler/AsmRegistersHandler.hpp"

class Expression: public AstNode {
public:
    Expression(Type const * type, size_t line, size_t column) noexcept;
    
    Type const * getType() const noexcept;
    
    bool isKindOf(Type const * type) const noexcept;
    
    
    virtual void compile(
        AssemblerValue::Size type,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmRegister::Type destination
    ) const noexcept = 0;
private:
    const Type * const type;
};

#endif /* Expression_hpp */
