//
//  LattePrintString.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef LattePrintString_hpp
#define LattePrintString_hpp

#include "BuiltinFunc.hpp"

class LattePrintString final: public BuiltinFunc {
public:
    LattePrintString(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* LattePrintString_hpp */
