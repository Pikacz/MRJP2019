//
//  BoolConstant.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef BoolConstant_hpp
#define BoolConstant_hpp

#include "Constant.hpp"
#include "../../../environment/Environment.hpp"

class BoolConstant final: public Constant<bool> {
public:
    BoolConstant(bool value, Environment const & env, size_t line, size_t column) noexcept;
};

#endif /* BoolConstant_hpp */
