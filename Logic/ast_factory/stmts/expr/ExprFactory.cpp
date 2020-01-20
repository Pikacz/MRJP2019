//
//  ExprFactory.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "ExprFactory.hpp"

#include "../../../ast/expressions/bool/boolExprs/BoolOrExpr.hpp"
#include "../../../ast/expressions/bool/boolExprs/BoolAndExpr.hpp"
#include "../../../ast/expressions/bool/compareExpr/CompareLess.hpp"
#include "../../../ast/expressions/bool/compareExpr/CompareLessEqual.hpp"
#include "../../../ast/expressions/bool/compareExpr/CompareGreater.hpp"
#include "../../../ast/expressions/bool/compareExpr/CompareGreaterEqual.hpp"
#include "../../../ast/expressions/bool/compareExpr/CompareEqual.hpp"
#include "../../../ast/expressions/bool/compareExpr/CompareNotEqual.hpp"
#include "../../../ast/expressions/bool/NotExpr.hpp"
#include "../../../ast/expressions/VarExpression.hpp"
#include "../../../ast/expressions/ExprCall.hpp"
#include "../../../ast/expressions/arithmetic/IntAdd.hpp"
#include "../../../ast/expressions/arithmetic/IntSub.hpp"
#include "../../../ast/expressions/arithmetic/IntMul.hpp"
#include "../../../ast/expressions/arithmetic/IntMod.hpp"
#include "../../../ast/expressions/arithmetic/IntDiv.hpp"
#include "../../../ast/expressions/constants/IntConstant.hpp"
#include "../../../ast/expressions/constants/BoolConstant.hpp"
#include "../../../ast/expressions/constants/StringConstant.hpp"

#include "../../../environment/variables/FuncVariable.hpp"



using namespace std;
using namespace antlr4;


static unique_ptr<const Expression> getExpr7(
    Environment * env, LatteParser::Expr7Context * ctx
) noexcept(false);


unique_ptr<const Expression> ExprFactory::getExpr(
    Environment * env, LatteParser::ExprContext * ctx
) noexcept(false) {
    return getExpr7(env, ctx->expr7());
}

// MARK: - expr 7
static unique_ptr<const Expression> getExpr6(
    Environment * env, LatteParser::Expr6Context * ctx
) noexcept(false);

static unique_ptr<const Expression> getExpr7(
    Environment * env, LatteParser::Expr7Context * ctx
) noexcept(false) {
    if (auto orToken = ctx->OOr()) {
        auto lhs = getExpr6(env, ctx->expr6());
        auto rhs = getExpr7(env, ctx->expr7());
        
        return make_unique<BoolOrExpr>(
            env,
            orToken->getSymbol()->getLine(),
            orToken->getSymbol()->getCharPositionInLine(),
            move(lhs),
            move(rhs)
        );
    }
    return getExpr6(env, ctx->expr6());
}

// MARK: - expr 6
static unique_ptr<const Expression> getExpr5(
    Environment * env, LatteParser::Expr5Context * ctx
) noexcept(false);


static unique_ptr<const Expression> getExpr6(
    Environment * env, LatteParser::Expr6Context * ctx
) noexcept(false) {
    if (auto andToken = ctx->OAnd()) {
        auto lhs = getExpr5(env, ctx->expr5());
        auto rhs = getExpr6(env, ctx->expr6());
        
        return make_unique<BoolAndExpr>(
            env,
            andToken->getSymbol()->getLine(),
            andToken->getSymbol()->getCharPositionInLine(),
            move(lhs),
            move(rhs)
        );
    }
    return getExpr5(env, ctx->expr5());
}


// MARK: - expr 5
static unique_ptr<const Expression> getExpr4(
    Environment * env, LatteParser::Expr4Context * ctx
) noexcept(false);

static unique_ptr<const Expression> getExpr5(
    Environment * env, LatteParser::Expr5Context * ctx
) noexcept(false) {
    if (auto ltToken = ctx->OLT()) {
        return make_unique<CompareLess>(
            env,
            ltToken->getSymbol()->getLine(),
            ltToken->getSymbol()->getCharPositionInLine(),
            getExpr5(env, ctx->expr5()),
            getExpr4(env, ctx->expr4())
        );
    } else if (auto lteToken = ctx->OLTE()) {
        return make_unique<CompareLessEqual>(
            env,
            lteToken->getSymbol()->getLine(),
            lteToken->getSymbol()->getCharPositionInLine(),
            getExpr5(env, ctx->expr5()),
            getExpr4(env, ctx->expr4())
        );
    } else if (auto gtToken = ctx->OGT()) {
        return make_unique<CompareGreater>(
            env,
            gtToken->getSymbol()->getLine(),
            gtToken->getSymbol()->getCharPositionInLine(),
            getExpr5(env, ctx->expr5()),
            getExpr4(env, ctx->expr4())
        );
    } else if (auto gteToken = ctx->OGTE()) {
        return make_unique<CompareGreaterEqual>(
            env,
            gteToken->getSymbol()->getLine(),
            gteToken->getSymbol()->getCharPositionInLine(),
            getExpr5(env, ctx->expr5()),
            getExpr4(env, ctx->expr4())
        );
    } else if (auto eqToken = ctx->OEq()) {
        return make_unique<CompareEqual>(
            env,
            eqToken->getSymbol()->getLine(),
            eqToken->getSymbol()->getCharPositionInLine(),
            getExpr5(env, ctx->expr5()),
            getExpr4(env, ctx->expr4())
        );
    } else if (auto neqToken = ctx->ONEq()) {
        return make_unique<CompareNotEqual>(
            env,
            neqToken->getSymbol()->getLine(),
            neqToken->getSymbol()->getCharPositionInLine(),
            getExpr5(env, ctx->expr5()),
            getExpr4(env, ctx->expr4())
        );
    }
    
    
    return getExpr4(env, ctx->expr4());
}

// MARK: - expr 4
static unique_ptr<const Expression> getExpr3(
    Environment * env, LatteParser::Expr3Context * ctx
) noexcept(false);


static unique_ptr<const Expression> getExpr4(
    Environment * env, LatteParser::Expr4Context * ctx
) noexcept(false) {
    if (auto oPlus = ctx->OPlus()) {
        auto lhs = getExpr4(env, ctx->expr4());
        auto rhs = getExpr3(env, ctx->expr3());
        
        if (lhs.get()->isKindOf(env->getLatteInt())) {
            return make_unique<IntAdd>(
                env,
                oPlus->getSymbol()->getLine(),
                oPlus->getSymbol()->getCharPositionInLine(),
                move(lhs),
                move(rhs)
            );
            
        } else {
            unique_ptr<const Expression> func;
            auto f = env->getConcatStrings();
            auto symbol = ctx->OPlus()->getSymbol();
            func = make_unique<VarExpression>(
                symbol->getLine(), symbol->getCharPositionInLine(), f
            );
            
            vector<unique_ptr<const Expression>> params;
            params.push_back(move(lhs));
            params.push_back(move(rhs));
            
            
            return make_unique<ExprCall>(
                ctx->getStart()->getLine(),
                ctx->getStart()->getCharPositionInLine(),
                env,
                move(func),
                move(params)
            );
        }
    } else if (auto oMinus = ctx->OMinus()) {
        return make_unique<IntSub>(
            env,
            oMinus->getSymbol()->getLine(),
            oMinus->getSymbol()->getCharPositionInLine(),
            getExpr4(env, ctx->expr4()),
            getExpr3(env, ctx->expr3())
        );
    }
    return getExpr3(env, ctx->expr3());
}


// MARK: - expr 3
static unique_ptr<const Expression> getExpr2(
    Environment * env, LatteParser::Expr2Context * ctx
) noexcept(false);


static unique_ptr<const Expression> getExpr3(
    Environment * env, LatteParser::Expr3Context * ctx
) noexcept(false) {
    if (auto oMul = ctx->OMul()) {
        return make_unique<IntMul>(
            env,
            oMul->getSymbol()->getLine(),
            oMul->getSymbol()->getCharPositionInLine(),
            getExpr3(env, ctx->expr3()),
            getExpr2(env, ctx->expr2())
        );
    } else if (auto oMod = ctx->OMod()) {
        return make_unique<IntMod>(
            env,
            oMod->getSymbol()->getLine(),
            oMod->getSymbol()->getCharPositionInLine(),
            getExpr3(env, ctx->expr3()),
            getExpr2(env, ctx->expr2())
        );
    } else if (auto oDiv = ctx->ODiv()) {
        return make_unique<IntDiv>(
            env,
            oDiv->getSymbol()->getLine(),
            oDiv->getSymbol()->getCharPositionInLine(),
            getExpr3(env, ctx->expr3()),
            getExpr2(env, ctx->expr2())
        );
    }
    
    return getExpr2(env, ctx->expr2());
}


// MARK: - expr 2
static unique_ptr<const Expression> getExpr1(
    Environment * env, LatteParser::Expr1Context * ctx
) noexcept(false);


static unique_ptr<const Expression> getExpr2(
    Environment * env, LatteParser::Expr2Context * ctx
) noexcept(false) {
    
    if (auto nm = ctx->Identifier()) {
        throw "TODO";
    } else if (ctx->OArrBL()) {
        throw "TODO";
    } else if (ctx->ParBL() != nullptr) {
        auto func = getExpr2(env, ctx->expr2());
        vector<unique_ptr<const Expression>> params;
        
        auto callList = ctx->callList();
        if (callList != nullptr) {
            for (auto & p: ctx->callList()->expr()) {
                params.push_back(ExprFactory::getExpr(env, p));
            }
        }
        
        return make_unique<ExprCall>(
            ctx->getStart()->getLine(),
            ctx->getStart()->getCharPositionInLine(),
            env,
            move(func),
            move(params)
        );
        
    }
    return getExpr1(env, ctx->expr1());
}


// MARK: - expr 1



static string getStringVal(tree::TerminalNode * ctx) noexcept;

static unique_ptr<const Expression> getExpr1(
    Environment * env, LatteParser::Expr1Context * ctx
) noexcept(false) {
    if (auto intConst = ctx->expr1IntConstant()) {
        auto intLit = intConst->IntLiteral();
        int val = stoi(intLit->getText());
        return make_unique<IntConstant>(
            val,
            env,
            intLit->getSymbol()->getLine(),
            intLit->getSymbol()->getCharPositionInLine()
        );
    } else if (auto strConst = ctx->expr1StringConstant()) {
        auto strLit = strConst->StringLiteral();
        string val = getStringVal(strLit);
        return make_unique<StringConstant>(
            val,
            env,
            strLit->getSymbol()->getLine(),
            strLit->getSymbol()->getCharPositionInLine()
        );
    } else if (auto boolConst = ctx->expr1BoolConstant()) {
        Token * token;
        bool val;
        if (auto t = boolConst->KTrue()) {
            token = t->getSymbol();
            val = true;
        } else {
            token = boolConst->KFalse()->getSymbol();
            val = false;
        }
        return make_unique<BoolConstant>(
            val,
            env,
            token->getLine(),
            token->getCharPositionInLine()
        );
    } else if (auto varExpr = ctx->expr1Variable()) {
        string name = varExpr->Identifier()->getText();
        Token * token = varExpr->Identifier()->getSymbol();
        auto var = env->getVariableNamed(
            name, token->getLine(), token->getCharPositionInLine()
        );
        return make_unique<VarExpression>(
            token->getLine(), token->getCharPositionInLine(), var
        );
    } else if (auto exprMinus = ctx->expr1Minus()) {
        Token * token = exprMinus->OMinus()->getSymbol();
        
        return make_unique<IntSub>(
            env,
            token->getLine(),
            token->getCharPositionInLine(),
            make_unique<IntConstant>(0, env, -1, -1),
            getExpr1(env, exprMinus->expr1())
        );
    } else if (auto exprNot = ctx->expr1Not()) {
        Token * token = exprNot->ONot()->getSymbol();
        return make_unique<NotExpr>(
            env,
            token->getLine(),
            token->getCharPositionInLine(),
            getExpr1(env, exprNot->expr1())
        );
    } else if (auto exprPar = ctx->expr1Par()) {
        return ExprFactory::getExpr(env, exprPar->expr());
    } else if (auto exprNewArray = ctx->expr1NewArray()) {
        throw "TODO";
    }
    auto newObj = ctx->expr1NewObject();
    throw "TODO";
}


static void replaceAll(
    string& source,
    const string& from,
    const string& to
) {
    string newString;
    newString.reserve(source.length());  // avoids a few memory allocations

    string::size_type lastPos = 0;
    string::size_type findPos;

    while(string::npos != (findPos = source.find(from, lastPos))) {
        newString.append(source, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }

    // Care for the rest after last occurrence
    newString += source.substr(lastPos);

    source.swap(newString);
}


static string getStringVal(tree::TerminalNode * ctx) noexcept {
    string result = ctx->getText();
    replaceAll(result, "\\n", "\n");
    replaceAll(result, "\\\\", "\\");
    replaceAll(result, "\\\"", "\"");

    result.erase(0, 1);
    result.erase(result.size() - 1);
    return result;
}
