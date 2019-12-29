//
//  Expression.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include "../AstNode.hpp"
#include "../../environment/types/Type.hpp"

class Expression: public AstNode {
public:
    Expression(Type const * type, size_t line, size_t column) noexcept;
    
    Type const * getType() const noexcept;
    
    bool isKindOf(Type const * type) const noexcept;
    
    size_t getLine() const noexcept;
    
    size_t getColumn() const noexcept;
private:
    const Type * const type;
    const size_t line, column;
};

#endif /* Expression_hpp */
