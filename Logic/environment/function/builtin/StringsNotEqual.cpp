//
//  StringsNotEqual.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "StringsNotEqual.hpp"
#include "../../Platform.hpp"

using namespace std;


StringsNotEqual::StringsNotEqual(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteBool(),
            "1 str not eq (nielegalna nazwa)",
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


string StringsNotEqual::getCompiledName() const noexcept {
    if (isOSx()) {
        return "__Z15stringsNotEqualPvS_";
    } else {
        return "_Z15stringsNotEqualPvS_";
    }
}
