//
//  StatementFactory.cpp
//  Logic
//
//  Created by Paweł Czerwiński on 13/01/2020.
//  Copyright © 2020 Paweł Czerwiński. All rights reserved.
//

#include "StatementFactory.hpp"

#include <optional>

#include "../../ast/statements/BlockStatement.hpp"
#include "../../ast/statements/ReturnStatement.hpp"
#include "../../ast/statements/DeclareStatement.hpp"
#include "../../ast/statements/AssignementStatement.hpp"
#include "../../ast/statements/ExprStatement.hpp"
#include "../../ast/statements/IfStatement.hpp"
#include "../../ast/statements/WhileStatement.hpp"
#include "../../ast/expressions/VarExpression.hpp"
#include "../../ast/expressions/arithmetic/IntAdd.hpp"
#include "../../ast/expressions/arithmetic/IntSub.hpp"
#include "../../ast/expressions/constants/IntConstant.hpp"
#include "expr/ExprFactory.hpp"
#include "DecFactory.hpp"

using namespace std;
using namespace antlr4;


static void getDeclareStmt(
    BlockEnvironment * env,
    LatteParser::DecTypeContext * tctx,
    vector<LatteParser::DecVarContext *> const & ctx,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);


static void getAssStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * lhs,
    LatteParser::ExprContext * rhs,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);


static void getIncStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);


static void getDecStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);

static void getReturnStmt(
    BlockEnvironment * env,
    tree::TerminalNode* retToken,
    LatteParser::ExprContext * expr,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);

static void getIfStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    LatteParser::StmtContext * ifTrue,
    LatteParser::StmtContext * ifFalse,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);

static void getWhileStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    LatteParser::StmtContext * body,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);


static void getExprStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    vector<unique_ptr<const Statement>> & result
) noexcept(false);


void StatementFactory::getStatements(
    BlockEnvironment * env,
    LatteParser::StmtContext * ctx,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto exprs = ctx->expr();
    auto stmts = ctx->stmt();
    
    
    if (auto bCtx = ctx->block()) {
        getStatements(env, bCtx, result);
        return;
    }
    
    if (auto tCtx = ctx->decType()) {
        auto vCtx = ctx->decVar();
        getDeclareStmt(env, tCtx, vCtx, result);
        return;
    }
    
    if (ctx->OAss()) {
        if (exprs.size() == 2) {
            getAssStmt(
                env, exprs[0], exprs[1], ctx->OAss()->getSymbol(), result
            );
            return;
        }
    }
    
    if (ctx->OPlusPlus()) {
        if (exprs.size() == 1) {
            getIncStmt(env, exprs[0], ctx->OPlusPlus()->getSymbol(), result);
            return;
        }
    }
    
    if (ctx->OMinusMinus()) {
        if (exprs.size() == 1) {
            getDecStmt(env, exprs[0], ctx->OMinusMinus()->getSymbol(), result);
            return;
        }
    }
    
    if (auto retToken = ctx->Kreturn()) {
        if (exprs.size() == 1) {
            getReturnStmt(env, retToken, exprs[0], result);
            return;
        } else if (exprs.size() == 0) {
            getReturnStmt(env, retToken, nullptr, result);
            return;
        }
    }
    
    if (ctx->Kif()) {
        if (ctx->Kelse()) {
            if (exprs.size() == 1 && stmts.size() == 2) {
                getIfStmt(
                    env, exprs[0], stmts[0], stmts[1],
                    ctx->Kif()->getSymbol(), result
                );
                return;
            }
        } else {
            if (exprs.size() == 1 && stmts.size() == 1) {
                getIfStmt(
                    env, exprs[0], stmts[0], nullptr,
                    ctx->Kif()->getSymbol(), result
                );
                return;
            }
        }
    }
    
    if (ctx->Kwhile()) {
        if (exprs.size() == 1 && stmts.size() == 1) {
            getWhileStmt(
                env, exprs[0], stmts[0],
                ctx->Kwhile()->getSymbol(), result
            );
            return;
        }
    }
    
    if (exprs.size() == 1) {
        getExprStmt(env, exprs[0], result);
        return;
    }
    
}


void StatementFactory::getStatements(
    BlockEnvironment * env,
    LatteParser::BlockContext * ctx,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    unique_ptr<BlockStatement> block = make_unique<BlockStatement>(
        ctx->getStart()->getLine(),
        ctx->getStart()->getCharPositionInLine(),
        env
    );
    auto bEnv = block.get()->getEnvironment();
    vector<unique_ptr<const Statement>> body;
    
    for (auto & stmt : ctx->stmt()) {
        getStatements(bEnv, stmt, body);
    }
    block.get()->completeWith(move(body));
    
    result.push_back(move(block));
}


// MARK: - declaration
static void getDeclareStmt(
    BlockEnvironment * env,
    LatteParser::DecTypeContext * tctx,
    vector<LatteParser::DecVarContext *> const & ctx,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto type = DecFactory::getType(env, tctx);
    
    for (auto & var: ctx) {
        string name = var->Identifier()->getText();
        result.push_back(
            make_unique<DeclareStatement>(
                var->Identifier()->getSymbol()->getLine(),
                var->Identifier()->getSymbol()->getCharPositionInLine(),
                env,
                type,
                name
            )
        );
        
        if (var->OAss()) {
            auto _var = env->getVariableNamed(name, -1, -1);
            
            result.push_back(
                make_unique<AssignementStatement>(
                    var->OAss()->getSymbol()->getLine(),
                    var->OAss()->getSymbol()->getCharPositionInLine(),
                    make_unique<VarExpression>(-1, -1, _var),
                    ExprFactory::getExpr(env, var->expr())
                )
            );
        }
    }
}


// MARK: - assignement
static void getAssStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * _lhs,
    LatteParser::ExprContext * _rhs,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto lhs = ExprFactory::getExpr(env, _lhs);
    auto rhs = ExprFactory::getExpr(env, _rhs);
    
    auto ass = make_unique<AssignementStatement>(
        symbol->getLine(),
        symbol->getCharPositionInLine(),
        move(lhs),
        move(rhs)
    );
    result.push_back(move(ass));
}


// MARK: - incrementation
static void getIncStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto lhs = ExprFactory::getExpr(env, expr);
    
    auto var = ExprFactory::getExpr(env, expr);
    auto justOne = make_unique<IntConstant>(1, env, -1, -1);
    auto rhs = make_unique<IntAdd>(
        env, -1, -1, move(var), move(justOne)
    );
    
    auto inc = make_unique<AssignementStatement>(
        symbol->getLine(),
        symbol->getCharPositionInLine(),
        move(lhs),
        move(rhs)
    );
    
    result.push_back(move(inc));
}


// MARK: - decrementation
static void getDecStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * expr,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto lhs = ExprFactory::getExpr(env, expr);
    
    auto var = ExprFactory::getExpr(env, expr);
    auto justOne = make_unique<IntConstant>(1, env, -1, -1);
    auto rhs = make_unique<IntSub>(
        env, -1, -1, move(var), move(justOne)
    );
    
    auto inc = make_unique<AssignementStatement>(
        symbol->getLine(),
        symbol->getCharPositionInLine(),
        move(lhs),
        move(rhs)
    );
    
    result.push_back(move(inc));
}


// MARK: - return
static void getReturnStmt(
    BlockEnvironment * env,
    tree::TerminalNode* retToken,
    LatteParser::ExprContext * _expr,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    
    optional<unique_ptr<const Expression>> expr = nullopt;
    
    if (_expr) {
        expr = ExprFactory::getExpr(env, _expr);
    }
    
    result.push_back(
        make_unique<ReturnStatement>(
            retToken->getSymbol()->getLine(),
            retToken->getSymbol()->getCharPositionInLine(),
            env,
            move(expr)
        )
    );
}


// MARK: - if
static void getIfStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * _expr,
    LatteParser::StmtContext * _ifTrue,
    LatteParser::StmtContext * _ifFalse,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto expr = ExprFactory::getExpr(env, _expr);
    
    unique_ptr<BlockStatement> ifTrueBlock = make_unique<BlockStatement>(
        _ifTrue->getStart()->getLine(),
        _ifTrue->getStart()->getCharPositionInLine(),
        env
    );
    auto ifTrueEnv = ifTrueBlock.get()->getEnvironment();
    vector<unique_ptr<const Statement>> ifTrueBody;
    StatementFactory::getStatements(ifTrueEnv, _ifTrue, ifTrueBody);
    ifTrueBlock.get()->completeWith(move(ifTrueBody));
    
    unique_ptr<BlockStatement> ifFalseBlock;
    
    if (_ifFalse) {
        ifFalseBlock = make_unique<BlockStatement>(
            _ifFalse->getStart()->getLine(),
            _ifFalse->getStart()->getCharPositionInLine(),
            env
        );
        auto ifFalseEnv = ifFalseBlock.get()->getEnvironment();
        vector<unique_ptr<const Statement>> ifFalseBody;
        StatementFactory::getStatements(ifFalseEnv, _ifFalse, ifFalseBody);
        ifFalseBlock.get()->completeWith(move(ifFalseBody));
    } else {
        ifFalseBlock = make_unique<BlockStatement>(
            -1,
            -1,
            env
        );
        ifFalseBlock.get()->completeWith({});
    }
    
    
    auto ifS = make_unique<IfStatement>(
        symbol->getLine(), symbol->getCharPositionInLine(),
        env, move(expr), move(ifTrueBlock), move(ifFalseBlock)
    );
    result.push_back(move(ifS));
}


// MARK: - while
static void getWhileStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * _expr,
    LatteParser::StmtContext * _body,
    Token* symbol,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto expr = ExprFactory::getExpr(env, _expr);
       
    unique_ptr<BlockStatement> bodyBlock = make_unique<BlockStatement>(
       _body->getStart()->getLine(),
       _body->getStart()->getCharPositionInLine(),
       env
    );
    auto bodyEnv = bodyBlock.get()->getEnvironment();
    vector<unique_ptr<const Statement>> bodyBody;
    StatementFactory::getStatements(bodyEnv, _body, bodyBody);
    bodyBlock.get()->completeWith(move(bodyBody));

    auto wS = make_unique<WhileStatement>(
       symbol->getLine(), symbol->getCharPositionInLine(),
       env, move(expr), move(bodyBlock)
    );
    result.push_back(move(wS));
}


// MARK: - expression
static void getExprStmt(
    BlockEnvironment * env,
    LatteParser::ExprContext * _expr,
    vector<unique_ptr<const Statement>> & result
) noexcept(false) {
    auto expr = ExprFactory::getExpr(env, _expr);
    
    result.push_back(
        make_unique<ExprStatement>(
            _expr->getStart()->getLine(),
            _expr->getStart()->getCharPositionInLine(),
            move(expr)
        )
    );
}
