//
//  ConcatString.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ConcatString.hpp"

using namespace std;


ConcatString::ConcatString(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteString(),
            "1 concat (nielegalna nazwa)",
            {
                FunctionInitializer::Parameter(
                    globalEnv->getLatteString(), "s1", -1, -1
                ),
                FunctionInitializer::Parameter(
                    globalEnv->getLatteString(), "s2", -1, -1
                )
            }
        ),
        globalEnv
) {
    
}


string ConcatString::getCompiledName() const noexcept {
    return "__Z13concatStringsPvS_";
}
