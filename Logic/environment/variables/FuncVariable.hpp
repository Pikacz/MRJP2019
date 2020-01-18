//
//  FuncVariable.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 14/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef FuncVariable_hpp
#define FuncVariable_hpp

#include "Variable.hpp"
#include "../../assembler/AsmLabelHandler.hpp"
#include "../function/Function.hpp"


class FuncVariable: public Variable {
public:
    FuncVariable(Function const * func, Environment const * env) noexcept;
    
    
    void compileCall(
        AssemblerValue::Size size,
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        Environment const * env,
        AsmRegistersHandler & handler,
        AsmLabelHandler & lblHandler
    ) const noexcept;
    
    Function const * getFunction() const noexcept;

private:
    const Function * const func;
};

#endif /* FuncVariable_hpp */
