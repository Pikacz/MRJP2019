//
//  StringConstant.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#include "StringConstant.hpp"

using namespace std;


StringConstant::StringConstant(
    string value, Environment const & env, size_t line, size_t column
) noexcept: Constant<string>(value, env.getLatteString(), line, column) {}
