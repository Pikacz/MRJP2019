//
//  LatteError.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "LatteError.hpp"
#include "../../Platform.hpp"

using namespace std;


LatteError::LatteError(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteVoid(),
            "error",
            {
        
            }
        ),
        globalEnv
) {
    
}


string LatteError::getCompiledName() const noexcept {
    
    if (isOSx()) {
        return "__Z5errorv";
    } else {
        return "_Z5errorv";
    }
}
