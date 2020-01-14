
// Generated from Latte.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LatteParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LatteParser.
 */
class  LatteListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(LatteParser::MainContext *ctx) = 0;
  virtual void exitMain(LatteParser::MainContext *ctx) = 0;

  virtual void enterTopDef(LatteParser::TopDefContext *ctx) = 0;
  virtual void exitTopDef(LatteParser::TopDefContext *ctx) = 0;

  virtual void enterType(LatteParser::TypeContext *ctx) = 0;
  virtual void exitType(LatteParser::TypeContext *ctx) = 0;

  virtual void enterTypeMember(LatteParser::TypeMemberContext *ctx) = 0;
  virtual void exitTypeMember(LatteParser::TypeMemberContext *ctx) = 0;

  virtual void enterFunction(LatteParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(LatteParser::FunctionContext *ctx) = 0;

  virtual void enterFuncArgs(LatteParser::FuncArgsContext *ctx) = 0;
  virtual void exitFuncArgs(LatteParser::FuncArgsContext *ctx) = 0;

  virtual void enterArg(LatteParser::ArgContext *ctx) = 0;
  virtual void exitArg(LatteParser::ArgContext *ctx) = 0;

  virtual void enterStmt(LatteParser::StmtContext *ctx) = 0;
  virtual void exitStmt(LatteParser::StmtContext *ctx) = 0;

  virtual void enterBlock(LatteParser::BlockContext *ctx) = 0;
  virtual void exitBlock(LatteParser::BlockContext *ctx) = 0;

  virtual void enterDecVar(LatteParser::DecVarContext *ctx) = 0;
  virtual void exitDecVar(LatteParser::DecVarContext *ctx) = 0;

  virtual void enterDecType(LatteParser::DecTypeContext *ctx) = 0;
  virtual void exitDecType(LatteParser::DecTypeContext *ctx) = 0;

  virtual void enterTypeName(LatteParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(LatteParser::TypeNameContext *ctx) = 0;

  virtual void enterExpr(LatteParser::ExprContext *ctx) = 0;
  virtual void exitExpr(LatteParser::ExprContext *ctx) = 0;

  virtual void enterExpr7(LatteParser::Expr7Context *ctx) = 0;
  virtual void exitExpr7(LatteParser::Expr7Context *ctx) = 0;

  virtual void enterExpr6(LatteParser::Expr6Context *ctx) = 0;
  virtual void exitExpr6(LatteParser::Expr6Context *ctx) = 0;

  virtual void enterExpr5(LatteParser::Expr5Context *ctx) = 0;
  virtual void exitExpr5(LatteParser::Expr5Context *ctx) = 0;

  virtual void enterExpr4(LatteParser::Expr4Context *ctx) = 0;
  virtual void exitExpr4(LatteParser::Expr4Context *ctx) = 0;

  virtual void enterExpr3(LatteParser::Expr3Context *ctx) = 0;
  virtual void exitExpr3(LatteParser::Expr3Context *ctx) = 0;

  virtual void enterExpr2(LatteParser::Expr2Context *ctx) = 0;
  virtual void exitExpr2(LatteParser::Expr2Context *ctx) = 0;

  virtual void enterExpr1(LatteParser::Expr1Context *ctx) = 0;
  virtual void exitExpr1(LatteParser::Expr1Context *ctx) = 0;

  virtual void enterExpr1IntConstant(LatteParser::Expr1IntConstantContext *ctx) = 0;
  virtual void exitExpr1IntConstant(LatteParser::Expr1IntConstantContext *ctx) = 0;

  virtual void enterExpr1StringConstant(LatteParser::Expr1StringConstantContext *ctx) = 0;
  virtual void exitExpr1StringConstant(LatteParser::Expr1StringConstantContext *ctx) = 0;

  virtual void enterExpr1BoolConstant(LatteParser::Expr1BoolConstantContext *ctx) = 0;
  virtual void exitExpr1BoolConstant(LatteParser::Expr1BoolConstantContext *ctx) = 0;

  virtual void enterExpr1Variable(LatteParser::Expr1VariableContext *ctx) = 0;
  virtual void exitExpr1Variable(LatteParser::Expr1VariableContext *ctx) = 0;

  virtual void enterExpr1Minus(LatteParser::Expr1MinusContext *ctx) = 0;
  virtual void exitExpr1Minus(LatteParser::Expr1MinusContext *ctx) = 0;

  virtual void enterExpr1Not(LatteParser::Expr1NotContext *ctx) = 0;
  virtual void exitExpr1Not(LatteParser::Expr1NotContext *ctx) = 0;

  virtual void enterExpr1Par(LatteParser::Expr1ParContext *ctx) = 0;
  virtual void exitExpr1Par(LatteParser::Expr1ParContext *ctx) = 0;

  virtual void enterExpr1NewArray(LatteParser::Expr1NewArrayContext *ctx) = 0;
  virtual void exitExpr1NewArray(LatteParser::Expr1NewArrayContext *ctx) = 0;

  virtual void enterExpr1NewObject(LatteParser::Expr1NewObjectContext *ctx) = 0;
  virtual void exitExpr1NewObject(LatteParser::Expr1NewObjectContext *ctx) = 0;

  virtual void enterCallList(LatteParser::CallListContext *ctx) = 0;
  virtual void exitCallList(LatteParser::CallListContext *ctx) = 0;


};

