//
//  FunctionInitializer.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 26/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef FunctionInitializer_hpp
#define FunctionInitializer_hpp

#include <string>

#include "../types/FunctionType.hpp"

class FunctionInitializer {
public:
    std::string getName() const noexcept;
    
    FunctionType const * getType() const noexcept;
};

#endif /* FunctionInitializer_hpp */
