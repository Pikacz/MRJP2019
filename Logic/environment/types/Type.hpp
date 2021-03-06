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
#include <list>
#include <memory>

#include "../../assembler/instructions/AsmInstruction.hpp"


class Variable;
class Type {
public:
    virtual ~Type();
    
    virtual bool isKindOf(Type const * type) const noexcept = 0;
    
    virtual std::string getName() const noexcept = 0;
    
    virtual size_t pointerSize() const noexcept = 0;
    
    virtual bool isVoid() const noexcept;
    
    virtual Variable const * getMemberNamed(std::string name, size_t line, size_t column) const noexcept(false);
    
    virtual void compile(
        std::list<std::unique_ptr<const AsmInstruction>> & compiled
    ) const noexcept;
    
    virtual bool isPointer() const noexcept;
    
    virtual bool isArray() const noexcept;
    
    virtual bool isObject() const noexcept;
};


#endif /* Type_hpp */
