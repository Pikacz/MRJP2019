//
//  Function.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 25/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp

#include <stdio.h>

#include "../../ast/statements/Statement.hpp"

#include "FunctionInitializer.hpp"
#include "../types/FunctionType.hpp"

#include <vector>
#include <memory>
#include <string>

class Environment;

class Function {
public:
    Function(
        FunctionInitializer initializer,
        Environment const * globalEnv
    ) noexcept;
    
    void completeWith(
        std::vector<std::unique_ptr<const Statement>> statements
    ) noexcept;
    
    Environment * getEnvironment() const noexcept;
private:
    const FunctionType * const type;
    
    std::vector<std::unique_ptr<const Statement>> statements;
    
    const std::unique_ptr<Environment> env;
    
    const std::string name;
    
    bool isCompleted;
};


#endif /* Function_hpp */
