//
//  ConcatString.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ConcatString_hpp
#define ConcatString_hpp

#include "BuiltinFunc.hpp"

class ConcatString final: public BuiltinFunc {
public:
    ConcatString(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* ConcatString_hpp */
