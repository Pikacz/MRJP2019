//
//  InvalidType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 23/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef InvalidType_hpp
#define InvalidType_hpp

#include <stdio.h>
#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class InvalidType: public StaticCheckError {
public:
    InvalidType(
        size_t line,
        size_t column,
        std::string expectedType,
        std::string recievedType
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const std::string expectedType;
    const std::string recievedType;
};

#endif /* InvalidType_hpp */
