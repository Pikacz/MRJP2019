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
#include "../../../ast/expressions/ExprArrayLength.hpp"
#include "../../../ast/expressions/ExprDot.hpp"
#include "../../../ast/expressions/ExprCompareObjects.hpp"
#include "../../../ast/expressions/ExprNull.hpp"
#include "../../../ast/expressions/ExprSubscript.hpp"
#include "../../../ast/expressions/ExprNewObject.hpp"
#include "../../../ast/expressions/ExprCall.hpp"
#include "../../../ast/expressions/ExprNewArray.hpp"
#include "../../../ast/expressions/arithmetic/IntAdd.hpp"
#include "../../../ast/expressions/arithmetic/IntSub.hpp"
#include "../../../ast/expressions/arithmetic/IntMul.hpp"
#include "../../../ast/expressions/arithmetic/IntMod.hpp"
#include "../../../ast/expressions/arithmetic/IntDiv.hpp"
#include "../../../ast/expressions/constants/IntConstant.hpp"
#include "../../../ast/expressions/constants/BoolConstant.hpp"
#include "../../../ast/expressions/constants/StringConstant.hpp"
#include "../DecFactory.hpp"

#include "../../../environment/variables/FuncVariable.hpp"


#include <cassert>

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
        auto lhs = getExpr5(env, ctx->expr5());
        auto rhs = getExpr4(env, ctx->expr4());
        if (lhs->isKindOf(env->getLatteInt()) || lhs->isKindOf(env->getLatteBool())) {
            return make_unique<CompareEqual>(
                env,
                eqToken->getSymbol()->getLine(),
                eqToken->getSymbol()->getCharPositionInLine(),
                move(lhs),
                move(rhs)
            );
        } else if (lhs->getType()->isObject()) {
            return make_unique<ExprCompareObjects>(
                env,
                eqToken->getSymbol()->getLine(),
                eqToken->getSymbol()->getCharPositionInLine(),
                move(lhs),
                move(rhs),
                true
            );
        } else {
            unique_ptr<const Expression> func;
            auto f = env->getEqualStrings();
            auto symbol = eqToken->getSymbol();
            func = make_unique<VarExpression>(
                symbol->getLine(), symbol->getCharPositionInLine(), f
            );
            
            vector<unique_ptr<const Expression>> params;
            params.push_back(move(lhs));
            params.push_back(move(rhs));
            
            
            return make_unique<ExprCall>(
                ctx->getStart()->getLine(),
                ctx->getStart()->getCharPositionInLine(),
                move(func),
                move(params)
            );
        }
        
    } else if (auto neqToken = ctx->ONEq()) {
        auto lhs = getExpr5(env, ctx->expr5());
        auto rhs = getExpr4(env, ctx->expr4());
        
        if (lhs->isKindOf(env->getLatteInt()) || lhs->isKindOf(env->getLatteBool())) {
            return make_unique<CompareNotEqual>(
                env,
                neqToken->getSymbol()->getLine(),
                neqToken->getSymbol()->getCharPositionInLine(),
                move(lhs),
                move(rhs)
            );
        } else if (lhs->getType()->isObject()) {
           return make_unique<ExprCompareObjects>(
               env,
               eqToken->getSymbol()->getLine(),
               eqToken->getSymbol()->getCharPositionInLine(),
               move(lhs),
               move(rhs),
               false
           );
       } else {
            unique_ptr<const Expression> func;
            auto f = env->getNotEqualStrings();
            auto symbol = neqToken->getSymbol();
            func = make_unique<VarExpression>(
                symbol->getLine(), symbol->getCharPositionInLine(), f
            );
            
            vector<unique_ptr<const Expression>> params;
            params.push_back(move(lhs));
            params.push_back(move(rhs));
            
            
            return make_unique<ExprCall>(
                ctx->getStart()->getLine(),
                ctx->getStart()->getCharPositionInLine(),
                move(func),
                move(params)
            );
        }
        
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
    Environment * env, LatteParser::Expr2Context * ctx, bool expectingFunction
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
            getExpr2(env, ctx->expr2(), false)
        );
    } else if (auto oMod = ctx->OMod()) {
        return make_unique<IntMod>(
            env,
            oMod->getSymbol()->getLine(),
            oMod->getSymbol()->getCharPositionInLine(),
            getExpr3(env, ctx->expr3()),
            getExpr2(env, ctx->expr2(), false)
        );
    } else if (auto oDiv = ctx->ODiv()) {
        return make_unique<IntDiv>(
            env,
            oDiv->getSymbol()->getLine(),
            oDiv->getSymbol()->getCharPositionInLine(),
            getExpr3(env, ctx->expr3()),
            getExpr2(env, ctx->expr2(), false)
        );
    }
    
    return getExpr2(env, ctx->expr2(), false);
}


// MARK: - expr 2
static unique_ptr<const Expression> getExpr1(
    Environment * env, LatteParser::Expr1Context * ctx, bool expectingFunction
) noexcept(false);


static unique_ptr<const Expression> getExpr2(
    Environment * env, LatteParser::Expr2Context * ctx, bool expectingFunction
) noexcept(false) {
    
    if (auto nm = ctx->Identifier()) {
        auto lhs = getExpr2(env, ctx->expr2(), expectingFunction);
        string name = nm->getText();
        auto nmToken = nm->getSymbol();
        
        if (lhs->getType()->isArray() && name == "length") {
            
            return make_unique<ExprArrayLength>(
                nmToken->getLine(), nmToken->getCharPositionInLine(), env, move(lhs)
            );
        }
        
        auto var = lhs->getType()->getMemberNamed(name, nmToken->getLine(), nmToken->getCharPositionInLine());
        auto varExpr = make_unique<VarExpression>(
            -1, -1, var
        );
        
        return make_unique<ExprDot>(-1, -1, move(lhs), move(varExpr));
    } else if (ctx->OArrBL()) {
        auto lhs = getExpr2(env, ctx->expr2(), false);
        auto expr = ExprFactory::getExpr(env, ctx->expr());
        auto token = ctx->OArrBL()->getSymbol();
        return make_unique<ExprSubscript>(token->getLine(), token->getCharPositionInLine(), env, move(lhs), move(expr));
    } else if (ctx->ParBL() != nullptr) {
        auto func = getExpr2(env, ctx->expr2(), true);
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
            move(func),
            move(params)
        );
        
    }
    return getExpr1(env, ctx->expr1(), expectingFunction);
}


// MARK: - expr 1



static string getStringVal(tree::TerminalNode * ctx) noexcept;

static unique_ptr<const Expression> getExpr1(
    Environment * env, LatteParser::Expr1Context * ctx, bool expectingFunction
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
    } else if (auto _varExpr = ctx->expr1Variable()) {
        string name = _varExpr->Identifier()->getText();
        Token * token = _varExpr->Identifier()->getSymbol();
        auto var = env->getVariableNamed(
            name, expectingFunction, token->getLine(), token->getCharPositionInLine()
        );
        auto varExpr = make_unique<VarExpression>(
            token->getLine(), token->getCharPositionInLine(), var
        );
        if (!var->isMemberVar()) {
            return move(varExpr);
        } else {
            auto _self = env->getVariableNamed("self", false, -1, -1);
            auto selfExpr = make_unique<VarExpression>(
                -1, -1, _self
            );
            
            return make_unique<ExprDot>(-1, -1, move(selfExpr), move(varExpr));
        }
        
    } else if (auto exprMinus = ctx->expr1Minus()) {
        Token * token = exprMinus->OMinus()->getSymbol();
        
        return make_unique<IntSub>(
            env,
            token->getLine(),
            token->getCharPositionInLine(),
            make_unique<IntConstant>(0, env, -1, -1),
            getExpr1(env, exprMinus->expr1(), expectingFunction)
        );
    } else if (auto exprNot = ctx->expr1Not()) {
        Token * token = exprNot->ONot()->getSymbol();
        return make_unique<NotExpr>(
            env,
            token->getLine(),
            token->getCharPositionInLine(),
            getExpr1(env, exprNot->expr1(), expectingFunction)
        );
    } else if (auto exprPar = ctx->expr1Par()) {
        return ExprFactory::getExpr(env, exprPar->expr());
    } else if (auto exprNewArray = ctx->expr1NewArray()) {
        Type const * type = DecFactory::getType(env, exprNewArray->decType());
        auto expr = ExprFactory::getExpr(env, exprNewArray->expr());
        auto newToken = exprNewArray->Knew()->getSymbol();
        return make_unique<ExprNewArray>(type, env, move(expr), newToken->getLine(), newToken->getCharPositionInLine());
    }
    if (auto newObj = ctx->expr1NewObject()) {
        auto tName = newObj->Identifier()->getText();
        auto tToken = newObj->Identifier()->getSymbol();
        auto type = env->getTypeNamed(tName, tToken->getLine(), tToken->getCharPositionInLine());
        
        auto nToken = newObj->Knew()->getSymbol();
        return make_unique<ExprNewObject>(type, nToken->getLine(), nToken->getCharPositionInLine());
    }
    
    if (auto nullECtx = ctx->expr1Null()) {
        auto tName = nullECtx->Identifier()->getText();
        auto tToken = nullECtx->Identifier()->getSymbol();
        auto type = env->getTypeNamed(tName, tToken->getLine(), tToken->getCharPositionInLine());
        auto nToken = nullECtx->KNull()->getSymbol();
        return make_unique<ExprNull>(nToken->getLine(), nToken->getCharPositionInLine(), type);
    }
    
    assert(false);
}

static string getStringVal(tree::TerminalNode * ctx) noexcept {
    string result = ctx->getText();

    result.erase(0, 1);
    result.erase(result.size() - 1);
    return result;
}
