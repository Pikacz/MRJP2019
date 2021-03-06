//
//  LattePrintString.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 16/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "LattePrintString.hpp"
#include "../../Platform.hpp"

using namespace std;


LattePrintString::LattePrintString(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteVoid(),
            "printString",
            {
                FunctionInitializer::Parameter(
                    globalEnv->getLatteString(), "", -1, -1
                )
            }
        ),
        globalEnv
) {
    
}


string LattePrintString::getCompiledName() const noexcept {
    if (isOSx()) {
        return "__Z11printStringPv";
    } else {
        return "_Z11printStringPv";
    }
}
