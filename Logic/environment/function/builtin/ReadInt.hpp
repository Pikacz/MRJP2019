//
//  ReadInt.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ReadInt_hpp
#define ReadInt_hpp

#include "BuiltinFunc.hpp"

class ReadInt final: public BuiltinFunc {
public:
    ReadInt(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* ReadInt_hpp */
