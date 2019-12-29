//
//  Logic.hpp
//  Logic
//
//  Created by Paweł Czerwiński on 21/12/2019.
//  Copyright © 2019 Paweł Czerwiński. All rights reserved.
//

#ifndef Logic_
#define Logic_

/* The classes below are exported */
#pragma GCC visibility push(default)

#include "assembler/values/AsmMemory.hpp"
#include "assembler/values/AsmIntConstant.hpp"

#include "ast/AstNode.hpp"
#include "ast/expressions/Expression.hpp"
#include "ast/expressions/constants/BoolConstant.hpp"
#include "ast/expressions/constants/IntConstant.hpp"
#include "ast/expressions/constants/StringConstant.hpp"

#include "environment/types/Type.hpp"
#include "environment/types/builtin/LatteBool.hpp"
#include "environment/types/builtin/LatteInt.hpp"
#include "environment/types/builtin/LatteString.hpp"
#include "environment/types/builtin/LatteVoid.hpp"
#include "environment/Environment.hpp"

#include "staticCheck/StaticCheckError.hpp"
#include "staticCheck/undefined/NoSuchTypeError.hpp"
#include "staticCheck/undefined/NoSuchVariableError.hpp"
#include "staticCheck/redeclaration/VariableRedeclarationError.hpp"


class Logic
{
    public:
    void HelloWorld(const char *);
};

#pragma GCC visibility pop
#endif
