//
//  LatteError.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef LatteError_hpp
#define LatteError_hpp

#include "BuiltinFunc.hpp"

class LatteError final: public BuiltinFunc {
public:
    LatteError(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* LatteError_hpp */
