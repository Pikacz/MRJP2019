//
//  FunctionType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 25/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef FunctionType_hpp
#define FunctionType_hpp

#include "Type.hpp"

#include <vector>

class FunctionType final: public Type {
public:
    FunctionType(
        Type const * returnType,
        std::vector<Type const *> parameters
    ) noexcept;
    
    bool isKindOf(Type const * type) const noexcept override;
    
    std::string getName() const noexcept override;
    
    size_t pointerSize() const noexcept override;
    
    Type const * getReturnType() const noexcept;
    
    std::vector<Type const *> getParameters() const noexcept;
    
private:
    const Type * const returnType;
    std::vector<Type const *> parameters;
};

#endif /* FunctionType_hpp */
