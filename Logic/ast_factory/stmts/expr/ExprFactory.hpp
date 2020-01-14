//
//  ExprFactory.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef ExprFactory_hpp
#define ExprFactory_hpp

#include <memory>

#include "../../../ast/expressions/Expression.hpp"
#include "../../../environment/Environment.hpp"
#include "../../../parser/LatteParser.h"

class ExprFactory final {
    public:
    static std::unique_ptr<const Expression> getExpr(
        Environment * env, LatteParser::ExprContext * ctx
    ) noexcept(false);
};

#endif /* ExprFactory_hpp */
