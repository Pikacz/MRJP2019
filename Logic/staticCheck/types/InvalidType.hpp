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
        Type const * expectedType,
        Type const * recievedType
    ) noexcept;
protected:
    const Type * const expectedType;
    const Type * const recievedType;
};

#endif /* InvalidType_hpp */
