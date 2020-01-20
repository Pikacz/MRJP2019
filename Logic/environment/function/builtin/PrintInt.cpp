//
//  PrintInt.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 15/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "PrintInt.hpp"


using namespace std;

#include "../../Platform.hpp"


PrintInt::PrintInt(
    Environment const * globalEnv
): BuiltinFunc(
        -1, -1,
        FunctionInitializer(
            globalEnv->getLatteVoid(),
            "printInt",
            {
                FunctionInitializer::Parameter(
                    globalEnv->getLatteInt(), "", -1, -1
                )
            }
        ),
        globalEnv
) {
    
}


string PrintInt::getCompiledName() const noexcept {
    if (isOSx()) {
        return "__Z8printIntx";
    } else {
        return "_Z8printIntx";
    }
}
