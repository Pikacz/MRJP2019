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

#include "../../assembler/instructions/AsmInstruction.hpp"
#include "../../ast/statements/Statement.hpp"
#include "FunctionInitializer.hpp"
#include "../types/FunctionType.hpp"
#include "../FunctionEnvironment.hpp"

#include <vector>
#include <memory>
#include <string>
#include <list>


class Function {
public:
    Function(
        size_t line, size_t column,
        FunctionInitializer initializer,
        Environment const * globalEnv,
        bool isMain = false
    ) noexcept;
    
    void completeWith(
        std::vector<std::unique_ptr<const Statement>> statements
    ) noexcept(false);
    
    FunctionEnvironment * getEnvironment() const noexcept;
    
    void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled,
        AsmLabelHandler & handler
    ) const noexcept;
private:
    const size_t line;
    const size_t column;
    const std::shared_ptr<const FunctionType> type;
    
    std::vector<std::unique_ptr<const Statement>> statements;
    
    const std::unique_ptr<FunctionEnvironment> env;
    
    const std::string name;
    
    bool isCompleted;
};


#endif /* Function_hpp */
