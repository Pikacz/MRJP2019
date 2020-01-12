//
//  MainFunction.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 04/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "MainFunction.hpp"
#include "../../staticCheck/main/MainInvalidType.hpp"


MainFunction::MainFunction(
    size_t line, size_t column,
    FunctionInitializer initializer,
    Environment const * globalEnv
) noexcept(false): Function(line, column, initializer, globalEnv, true) {
    if (initializer.getType()->getReturnType()->isKindOf(globalEnv->getLatteInt())) {
        if (initializer.getType()->getParameters().size() == 0) {
            return;
        }
    }
    throw MainInvalidType(line, column);
}
