//
//  PrintInt.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef PrintInt_hpp
#define PrintInt_hpp

#include <stdio.h>

#include "BuiltinFunc.hpp"

class PrintInt final: public BuiltinFunc {
public:
    PrintInt(Environment const * globalEnv);
    
    std::string getCompiledName() const noexcept override;
};

#endif /* PrintInt_hpp */
