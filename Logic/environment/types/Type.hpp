//
//  Type.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Type_hpp
#define Type_hpp

#include <string>

class Type {
public:
    virtual ~Type();
    
    virtual bool isKindOf(Type const * type) const noexcept = 0;
    
    virtual std::string getName() const noexcept = 0;
    
    virtual size_t pointerSize() const noexcept = 0;
};

#endif /* Type_hpp */
