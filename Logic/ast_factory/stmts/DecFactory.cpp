//
//  DecFactory.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "DecFactory.hpp"


Type const * DecFactory::getType(
    Environment * env, LatteParser::DecTypeContext * ctx
) noexcept(false) {
    auto parent = ctx->decType();
    if (parent != nullptr) {
        return env->getArrayOfType(getType(env, parent));
    }
    
    auto tName = ctx->typeName();
    
    if (tName->Kint() != nullptr) {
        return env->getLatteInt();
    } else if (tName->Kvoid()) {
        return env->getLatteVoid();
    } else if (tName->Kstring()) {
        return env->getLatteString();
    } else if (tName->Kbool()) {
        return env->getLatteBool();
    } else {
        auto nm = tName->Identifier();
        return env->getTypeNamed(
            nm->getText(),
            nm->getSymbol()->getLine(),
            nm->getSymbol()->getCharPositionInLine()
        );
    }
}
