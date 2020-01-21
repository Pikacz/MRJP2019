//
//  StringsEqual.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef StringsEqual_hpp
#define StringsEqual_hpp

#include "BuiltinFunc.hpp"

class StringsEqual final: public BuiltinFunc {
public:
    StringsEqual(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};


#endif /* StringsEqual_hpp */
