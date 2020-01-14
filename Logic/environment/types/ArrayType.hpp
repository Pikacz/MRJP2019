//
//  ArrayType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ArrayType_hpp
#define ArrayType_hpp

#include "Type.hpp"


class ArrayType final: public Type {
public:
    ArrayType(Type const * type) noexcept;
    
    bool isKindOf(Type const * type) const noexcept override;
    
    std::string getName() const noexcept override;
    
    size_t pointerSize() const noexcept override;
    
private:
    const Type * const type;
};




#endif /* ArrayType_hpp */
