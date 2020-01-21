//
//  EnvWithFunctions.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 20/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef EnvWithFunctions_hpp
#define EnvWithFunctions_hpp

#include "Environment.hpp"


class EnvWithFunctions: public Environment {
public:
    using Environment::Environment;
    
    
    virtual Function * declareFunction(
        FunctionInitializer initializer, size_t line, size_t column
    ) noexcept(false) = 0;
};


#endif /* EnvWithFunctions_hpp */
