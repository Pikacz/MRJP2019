//
//  StringsNotEqual.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef StringsNotEqual_hpp
#define StringsNotEqual_hpp

#include "BuiltinFunc.hpp"

class StringsNotEqual final: public BuiltinFunc {
public:
    StringsNotEqual(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* StringsNotEqual_hpp */
