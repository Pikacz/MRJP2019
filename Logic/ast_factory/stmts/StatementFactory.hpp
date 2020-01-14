//
//  StatementFactory.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#ifndef StatementFactory_hpp
#define StatementFactory_hpp

#include <memory>
#include <vector>

#include "../../ast/statements/Statement.hpp"
#include "../../environment/BlockEnvironment.hpp"
#include "../../parser/LatteParser.h"

class StatementFactory final {
public:
    static void getStatements(
        BlockEnvironment * env,
        LatteParser::StmtContext * ctx,
        std::vector<std::unique_ptr<const Statement>> & result
    ) noexcept(false);
    
    static void getStatements(
        BlockEnvironment * env,
        LatteParser::BlockContext * ctx,
        std::vector<std::unique_ptr<const Statement>> & result
    ) noexcept(false);
};

#endif /* StatementFactory_hpp */
