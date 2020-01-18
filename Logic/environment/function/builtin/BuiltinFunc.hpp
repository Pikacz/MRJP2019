//
//  BuiltinFunc.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef BuiltinFunc_hpp
#define BuiltinFunc_hpp

#include "../Function.hpp"


class BuiltinFunc: public Function {
public:
    using Function::Function;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmLabelHandler & handler
    ) const noexcept override;
};

#endif /* BuiltinFunc_hpp */
