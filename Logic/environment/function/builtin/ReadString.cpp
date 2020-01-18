//
//  ReadString.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ReadString.hpp"

using namespace std;


ReadString::ReadString(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteString(),
            "readString",
            {
            }
        ),
        globalEnv
) {
    
}


string ReadString::getCompiledName() const noexcept {
    return "__Z10readStringv";
}
