//
//  StringsEqual.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "StringsEqual.hpp"
#include "../../Platform.hpp"

using namespace std;


StringsEqual::StringsEqual(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteBool(),
            "1 str eq (nielegalna nazwa)",
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


string StringsEqual::getCompiledName() const noexcept {
    if (isOSx()) {
        return "__Z12stringsEqualPvS_";
    } else {
        return "_Z12stringsEqualPvS_";
    }
}
