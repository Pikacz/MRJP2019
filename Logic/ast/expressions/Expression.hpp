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
#include "../../assembler/AsmLabelHandler.hpp"

#include "../../ast_factory/VarValues.hpp"
#include <optional>

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
        AsmLabelHandler & lblHandler,
        AsmRegister::Type destination
    ) const noexcept = 0;
    
    virtual bool isTerminating() const noexcept;
    
    virtual void compileCall(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) const noexcept;
    
    virtual std::optional<bool> boolValue(VarValues const & values) const noexcept;
    
    virtual size_t fakeVariablesCount() const noexcept;
private:
    const Type * const type;
};

#endif /* Expression_hpp */
