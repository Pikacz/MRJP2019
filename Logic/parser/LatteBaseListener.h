
// Generated from Latte.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "LatteListener.h"


/**
 * This class provides an empty implementation of LatteListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LatteBaseListener : public LatteListener {
public:

  virtual void enterMain(LatteParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(LatteParser::MainContext * /*ctx*/) override { }

  virtual void enterTopDef(LatteParser::TopDefContext * /*ctx*/) override { }
  virtual void exitTopDef(LatteParser::TopDefContext * /*ctx*/) override { }

  virtual void enterType(LatteParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(LatteParser::TypeContext * /*ctx*/) override { }

  virtual void enterExtendBlock(LatteParser::ExtendBlockContext * /*ctx*/) override { }
  virtual void exitExtendBlock(LatteParser::ExtendBlockContext * /*ctx*/) override { }

  virtual void enterTypeMember(LatteParser::TypeMemberContext * /*ctx*/) override { }
  virtual void exitTypeMember(LatteParser::TypeMemberContext * /*ctx*/) override { }

  virtual void enterTypeVar(LatteParser::TypeVarContext * /*ctx*/) override { }
  virtual void exitTypeVar(LatteParser::TypeVarContext * /*ctx*/) override { }

  virtual void enterFunction(LatteParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(LatteParser::FunctionContext * /*ctx*/) override { }

  virtual void enterFuncArgs(LatteParser::FuncArgsContext * /*ctx*/) override { }
  virtual void exitFuncArgs(LatteParser::FuncArgsContext * /*ctx*/) override { }

  virtual void enterArg(LatteParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(LatteParser::ArgContext * /*ctx*/) override { }

  virtual void enterStmt(LatteParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(LatteParser::StmtContext * /*ctx*/) override { }

  virtual void enterBlock(LatteParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(LatteParser::BlockContext * /*ctx*/) override { }

  virtual void enterDecVar(LatteParser::DecVarContext * /*ctx*/) override { }
  virtual void exitDecVar(LatteParser::DecVarContext * /*ctx*/) override { }

  virtual void enterDecType(LatteParser::DecTypeContext * /*ctx*/) override { }
  virtual void exitDecType(LatteParser::DecTypeContext * /*ctx*/) override { }

  virtual void enterTypeName(LatteParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(LatteParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterExpr(LatteParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(LatteParser::ExprContext * /*ctx*/) override { }

  virtual void enterExpr7(LatteParser::Expr7Context * /*ctx*/) override { }
  virtual void exitExpr7(LatteParser::Expr7Context * /*ctx*/) override { }

  virtual void enterExpr6(LatteParser::Expr6Context * /*ctx*/) override { }
  virtual void exitExpr6(LatteParser::Expr6Context * /*ctx*/) override { }

  virtual void enterExpr5(LatteParser::Expr5Context * /*ctx*/) override { }
  virtual void exitExpr5(LatteParser::Expr5Context * /*ctx*/) override { }

  virtual void enterExpr4(LatteParser::Expr4Context * /*ctx*/) override { }
  virtual void exitExpr4(LatteParser::Expr4Context * /*ctx*/) override { }

  virtual void enterExpr3(LatteParser::Expr3Context * /*ctx*/) override { }
  virtual void exitExpr3(LatteParser::Expr3Context * /*ctx*/) override { }

  virtual void enterExpr2(LatteParser::Expr2Context * /*ctx*/) override { }
  virtual void exitExpr2(LatteParser::Expr2Context * /*ctx*/) override { }

  virtual void enterExpr1(LatteParser::Expr1Context * /*ctx*/) override { }
  virtual void exitExpr1(LatteParser::Expr1Context * /*ctx*/) override { }

  virtual void enterExpr1IntConstant(LatteParser::Expr1IntConstantContext * /*ctx*/) override { }
  virtual void exitExpr1IntConstant(LatteParser::Expr1IntConstantContext * /*ctx*/) override { }

  virtual void enterExpr1StringConstant(LatteParser::Expr1StringConstantContext * /*ctx*/) override { }
  virtual void exitExpr1StringConstant(LatteParser::Expr1StringConstantContext * /*ctx*/) override { }

  virtual void enterExpr1BoolConstant(LatteParser::Expr1BoolConstantContext * /*ctx*/) override { }
  virtual void exitExpr1BoolConstant(LatteParser::Expr1BoolConstantContext * /*ctx*/) override { }

  virtual void enterExpr1Variable(LatteParser::Expr1VariableContext * /*ctx*/) override { }
  virtual void exitExpr1Variable(LatteParser::Expr1VariableContext * /*ctx*/) override { }

  virtual void enterExpr1Minus(LatteParser::Expr1MinusContext * /*ctx*/) override { }
  virtual void exitExpr1Minus(LatteParser::Expr1MinusContext * /*ctx*/) override { }

  virtual void enterExpr1Not(LatteParser::Expr1NotContext * /*ctx*/) override { }
  virtual void exitExpr1Not(LatteParser::Expr1NotContext * /*ctx*/) override { }

  virtual void enterExpr1Par(LatteParser::Expr1ParContext * /*ctx*/) override { }
  virtual void exitExpr1Par(LatteParser::Expr1ParContext * /*ctx*/) override { }

  virtual void enterExpr1NewArray(LatteParser::Expr1NewArrayContext * /*ctx*/) override { }
  virtual void exitExpr1NewArray(LatteParser::Expr1NewArrayContext * /*ctx*/) override { }

  virtual void enterExpr1NewObject(LatteParser::Expr1NewObjectContext * /*ctx*/) override { }
  virtual void exitExpr1NewObject(LatteParser::Expr1NewObjectContext * /*ctx*/) override { }

  virtual void enterExpr1Null(LatteParser::Expr1NullContext * /*ctx*/) override { }
  virtual void exitExpr1Null(LatteParser::Expr1NullContext * /*ctx*/) override { }

  virtual void enterCallList(LatteParser::CallListContext * /*ctx*/) override { }
  virtual void exitCallList(LatteParser::CallListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

