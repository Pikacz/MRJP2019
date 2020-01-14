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
#include "ast/expressions/arithmetic/IntAdd.hpp"
#include "ast/expressions/arithmetic/IntSub.hpp"
#include "ast/expressions/arithmetic/IntMul.hpp"
#include "ast/expressions/arithmetic/IntDiv.hpp"
#include "ast/expressions/arithmetic/IntMod.hpp"
#include "ast/expressions/bool/boolExprs/BoolAndExpr.hpp"
#include "ast/expressions/bool/boolExprs/BoolOrExpr.hpp"
#include "ast/expressions/bool/compareExpr/CompareLess.hpp"
#include "ast/expressions/bool/compareExpr/CompareLessEqual.hpp"
#include "ast/expressions/bool/compareExpr/CompareGreater.hpp"
#include "ast/expressions/bool/compareExpr/CompareGreaterEqual.hpp"
#include "ast/expressions/bool/compareExpr/CompareEqual.hpp"
#include "ast/expressions/bool/compareExpr/CompareNotEqual.hpp"
#include "ast/expressions/bool/NotExpr.hpp"
#include "ast/expressions/VarExpression.hpp"

#include "ast/statements/Statement.hpp"
#include "ast/statements/AssignementStatement.hpp"
#include "ast/statements/DeclareStatement.hpp"
#include "ast/statements/ReturnStatement.hpp"
#include "ast/statements/BlockStatement.hpp"
#include "ast/statements/IfStatement.hpp"
#include "ast/statements/WhileStatement.hpp"

#include "environment/function/Function.hpp"
#include "environment/function/FunctionInitializer.hpp"
#include "environment/types/Type.hpp"
#include "environment/types/builtin/LatteBool.hpp"
#include "environment/types/builtin/LatteInt.hpp"
#include "environment/types/builtin/LatteString.hpp"
#include "environment/types/builtin/LatteVoid.hpp"
#include "environment/Environment.hpp"
#include "environment/GlobalEnvironment.hpp"

#include "staticCheck/ParserError.hpp"
#include "staticCheck/StaticCheckError.hpp"
#include "staticCheck/undefined/NoSuchTypeError.hpp"
#include "staticCheck/undefined/NoSuchVariableError.hpp"
#include "staticCheck/redeclaration/VariableRedeclarationError.hpp"

#include "parser/LatteParser.h"
#include "parser/LatteLexer.h"
#include "parser/LatteBaseListener.h"
#include "parser/LatteListener.h"

#include "ast_factory/TopDefFactory.hpp"


class Logic
{
    public:
    void HelloWorld(const char *);
};

#pragma GCC visibility pop
#endif
