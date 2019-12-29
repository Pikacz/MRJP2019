//
//  IntConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "IntConstant.hpp"

using namespace std;


IntConstant::IntConstant(
    int value, Environment const & env, size_t line, size_t column
) noexcept: Constant<int>(value, env.getLatteInt(), line, column) {}
