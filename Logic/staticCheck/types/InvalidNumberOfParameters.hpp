//
//  InvalidNumberOfParameters.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef InvalidNumberOfParameters_hpp
#define InvalidNumberOfParameters_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"
#include "../../environment/types/FunctionType.hpp"

class InvalidNumberOfParameters: public StaticCheckError {
public:
    InvalidNumberOfParameters(
        size_t line,
        size_t column,
        FunctionType const * recievedType,
        size_t recievedParameters
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const FunctionType * const recievedType;
    const size_t recievedParameters;
};

#endif /* InvalidNumberOfParameters_hpp */
