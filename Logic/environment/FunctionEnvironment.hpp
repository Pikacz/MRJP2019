//
//  FunctionEnvironment.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef FunctionEnvironment_hpp
#define FunctionEnvironment_hpp

#include <stdio.h>
#include "Environment.hpp"

#include <map>
#include <vector>
#include <memory>
#include <string>



class FunctionEnvironment final: public Environment {
public:
    FunctionEnvironment(Environment const * parent) noexcept;
    
    // MARK: variables
    void declareParameterVariable(
        std::string name,
        Type const * type,
        size_t line,
        size_t column
    ) noexcept(false);
    
    void declareVariable(
        std::string name, Type const * type, size_t line, size_t column
    ) noexcept(false);
    
    Variable const * getVariableNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: functions
    Function const * getFunctionNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
    
    // MARK: types
    Type const * getTypeNamed(
        std::string name, size_t line, size_t column
    ) const noexcept(false) override;
private:
    std::vector<
        std::pair<std::string, std::unique_ptr<const Variable>>
    > parameters;
    std::map<std::string, std::unique_ptr<const Variable>> variables;
    
    const Environment * const parent;
    
};

#endif /* FunctionEnvironment_hpp */
