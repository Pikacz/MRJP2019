//
//  Constant.hpp
//  Latte
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Constant_hpp
#define Constant_hpp

#include "../Expression.hpp"

template <class ValT>
class Constant: public Expression {
public:
    Constant(ValT value, Type const * type, size_t line, size_t column) noexcept:
        value(value), Expression(type, line, column) {}
    
    bool isEqualTo(AstNode const * node) const noexcept override {
        if (auto nd = dynamic_cast<Constant<ValT> const *>(node)) {
            return value == nd->value;
        }
        return false;
    }
    
    ValT getValue() const noexcept {
        return value;
    }
private:
    const ValT value;
};

#endif /* Constant_hpp */
