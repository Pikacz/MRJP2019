//
//  TypeNotAnObject.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef TypeNotAnObject_hpp
#define TypeNotAnObject_hpp

#include "../StaticCheckError.hpp"
#include "../../environment/types/Type.hpp"

class TypeNotAnObject: public StaticCheckError {
public:
    TypeNotAnObject(
        size_t line,
        size_t column,
        std::string type
    ) noexcept;
    
    virtual void description(std::stringstream & ss) const noexcept override;
protected:
    const std::string type;
};

#endif /* TypeNotAnObject_hpp */
