//
//  ExprCompareObjects.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprCompareObjects_hpp
#define ExprCompareObjects_hpp

#include "Expr2Arg.hpp"



class ExprCompareObjects: public Expr2Arg {
public:
    ExprCompareObjects(
        Environment const * env,
        size_t line,
        size_t column,
        std::unique_ptr<const Expression> lhs,
        std::unique_ptr<const Expression> rhs,
        bool equal
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

private:
    const bool checkIfEqual;
};


#endif /* ExprCompareObjects_hpp */
