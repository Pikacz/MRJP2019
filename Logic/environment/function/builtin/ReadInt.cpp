//
//  ReadInt.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ReadInt.hpp"
#include "../../Platform.hpp"

using namespace std;


ReadInt::ReadInt(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteInt(),
            "readInt",
            {
            }
        ),
        globalEnv
) {
    
}


string ReadInt::getCompiledName() const noexcept {
    if (isOSx()) {
        return "__Z7readIntv";
    } else {
        return "_Z7readIntv";
    }
}
