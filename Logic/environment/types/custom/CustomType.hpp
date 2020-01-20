//
//  CustomType.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef CustomType_hpp
#define CustomType_hpp

#include <optional>
#include <map>

#include "../Type.hpp"


class CustomType final: public Type {
public:
    CustomType(std::string name) noexcept;
    
    bool isKindOf(Type const * type) const noexcept override;
    
    std::string getName() const noexcept override;
    
    size_t pointerSize() const noexcept override;
    
    void setParent(
        CustomType const * parent, size_t line, size_t column
    ) noexcept(false);
    
    
    
protected:
    bool hasMemberNamed(std::string name) const noexcept;
    
    size_t getVarFooset() const noexcept;

private:
    const std::string name;
    std::optional<CustomType const *> parentType;
};


#endif /* CustomType_hpp */
