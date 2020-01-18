//
//  MainFunction.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef MainFunction_hpp
#define MainFunction_hpp

#include <stdio.h>

#include "Function.hpp"


class MainFunction final: public Function {
public:
    MainFunction(
        size_t line, size_t column,
        FunctionInitializer initializer,
        Environment const * globalEnv
    ) noexcept(false);
    
    virtual std::string getCompiledName() const noexcept override;
};

#endif /* MainFunction_hpp */
