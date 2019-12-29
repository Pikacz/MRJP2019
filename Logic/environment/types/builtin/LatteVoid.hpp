//
//  LatteVoid.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef LatteVoid_hpp
#define LatteVoid_hpp

#include "../Type.hpp"

class LatteVoid final: public Type {
public:
    using Type::Type;
    
    bool isKindOf(Type const * type) const noexcept override;
    
    std::string getName() const noexcept override;
    
    size_t pointerSize() const noexcept override;
};

#endif /* LatteVoid_hpp */
