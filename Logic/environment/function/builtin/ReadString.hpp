//
//  ReadString.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ReadString_hpp
#define ReadString_hpp

#include "BuiltinFunc.hpp"

class ReadString final: public BuiltinFunc {
public:
    ReadString(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* ReadString_hpp */
