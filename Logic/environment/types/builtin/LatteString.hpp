//
//  LatteString.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef LatteString_hpp
#define LatteString_hpp

#include "../Type.hpp"

class LatteString final: public Type {
public:
    using Type::Type;
    
    bool isKindOf(Type const * type) const noexcept override;
    
    std::string getName() const noexcept override;
    
    size_t pointerSize() const noexcept override;
};

#endif /* LatteString_hpp */
