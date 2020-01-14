//
//  DecFactory.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 12/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef DecFactory_hpp
#define DecFactory_hpp

#include <stdio.h>

#include "../../environment/Environment.hpp"
#include "../../parser/LatteParser.h"


class DecFactory final {
public:
    static Type const * getType(
        Environment * env, LatteParser::DecTypeContext * ctx
    ) noexcept(false);
};

#endif /* DecFactory_hpp */
