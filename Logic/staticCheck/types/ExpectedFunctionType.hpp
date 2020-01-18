//
//  ExpectedFunctionType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExpectedFunctionType_hpp
#define ExpectedFunctionType_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class ExpectedFunctionType: public StaticCheckError {
public:
    ExpectedFunctionType(
        size_t line,
        size_t column,
        Type const * recievedType
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const Type * const recievedType;
};


#endif /* ExpectedFunctionType_hpp */
