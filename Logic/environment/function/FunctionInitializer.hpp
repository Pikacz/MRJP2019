//
//  FunctionInitializer.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef FunctionInitializer_hpp
#define FunctionInitializer_hpp

#include <string>
#include <vector>
#include <memory>

#include "../types/FunctionType.hpp"

class FunctionInitializer {
public:
    class Parameter {
    public:
        Parameter(
            Type const * type,
            std::string name,
            size_t line,
            size_t column
        ) noexcept: type(type), name(name), line(line), column(column) {}
    
        Type const * const type;
        const std::string name;
        const size_t line;
        const size_t column;
    };
    
    FunctionInitializer(
        Type const * returnType,
        std::string name,
        std::vector<Parameter> parameters
    ) noexcept;
    
    
    std::string getName() const noexcept;
    
    std::shared_ptr<const FunctionType> getType() const noexcept;
    
private:
    const std::shared_ptr<const FunctionType> type;
    const std::string name;
    
    std::vector<Parameter> parameters;
};

#endif /* FunctionInitializer_hpp */
