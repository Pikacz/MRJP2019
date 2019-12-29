//
//  StringConstant.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 22/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef StringConstant_hpp
#define StringConstant_hpp

#include <string>
#include "Constant.hpp"
#include "../../../environment/Environment.hpp"

class StringConstant final: public Constant<std::string> {
public:
    StringConstant(std::string value, Environment const & env, size_t line, size_t column) noexcept;
};

#endif /* StringConstant_hpp */
