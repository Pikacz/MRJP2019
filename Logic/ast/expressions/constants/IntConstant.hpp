//
//  IntConstant.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef IntConstant_hpp
#define IntConstant_hpp

#include "Constant.hpp"
#include "../../../environment/Environment.hpp"

class IntConstant final: public Constant<int> {
public:
    IntConstant(int value, Environment const & env, size_t line, size_t column) noexcept;
};

#endif /* IntConstant_hpp */
