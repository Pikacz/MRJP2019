
// Generated from Latte.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  LatteParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    OPlus = 8, OMinus = 9, ODiv = 10, OMul = 11, OMod = 12, OPlusPlus = 13, 
    OMinusMinus = 14, OAss = 15, OLT = 16, OLTE = 17, OGT = 18, OGTE = 19, 
    OEq = 20, ONEq = 21, ONot = 22, OAnd = 23, OOr = 24, OArrBL = 25, OArrBR = 26, 
    Kreturn = 27, Kwhile = 28, Kif = 29, Kelse = 30, Kclass = 31, Kextends = 32, 
    Knew = 33, Kint = 34, Kstring = 35, Kvoid = 36, Kbool = 37, KTrue = 38, 
    KFalse = 39, Identifier = 40, IntLiteral = 41, StringLiteral = 42, Whitespace = 43, 
    BlockComment = 44, LineComment = 45
  };

  enum {
    RuleMain = 0, RuleTopDef = 1, RuleType = 2, RuleTypeMember = 3, RuleFunction = 4, 
    RuleFuncArgs = 5, RuleArg = 6, RuleStmt = 7, RuleBlock = 8, RuleDecVar = 9, 
    RuleDecType = 10, RuleTypeName = 11, RuleExpr = 12, RuleExpr7 = 13, 
    RuleExpr6 = 14, RuleExpr5 = 15, RuleExpr4 = 16, RuleExpr3 = 17, RuleExpr2 = 18, 
    RuleExpr1 = 19, RuleExpr1IntConstant = 20, RuleExpr1StringConstant = 21, 
    RuleExpr1BoolConstant = 22, RuleExpr1Variable = 23, RuleExpr1Minus = 24, 
    RuleExpr1Not = 25, RuleExpr1Par = 26, RuleExpr1NewArray = 27, RuleExpr1NewObject = 28, 
    RuleCallList = 29
  };

  LatteParser(antlr4::TokenStream *input);
  ~LatteParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class MainContext;
  class TopDefContext;
  class TypeContext;
  class TypeMemberContext;
  class FunctionContext;
  class FuncArgsContext;
  class ArgContext;
  class StmtContext;
  class BlockContext;
  class DecVarContext;
  class DecTypeContext;
  class TypeNameContext;
  class ExprContext;
  class Expr7Context;
  class Expr6Context;
  class Expr5Context;
  class Expr4Context;
  class Expr3Context;
  class Expr2Context;
  class Expr1Context;
  class Expr1IntConstantContext;
  class Expr1StringConstantContext;
  class Expr1BoolConstantContext;
  class Expr1VariableContext;
  class Expr1MinusContext;
  class Expr1NotContext;
  class Expr1ParContext;
  class Expr1NewArrayContext;
  class Expr1NewObjectContext;
  class CallListContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<TopDefContext *> topDef();
    TopDefContext* topDef(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MainContext* main();

  class  TopDefContext : public antlr4::ParserRuleContext {
  public:
    TopDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TopDefContext* topDef();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Kclass();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *Kextends();
    std::vector<TypeMemberContext *> typeMember();
    TypeMemberContext* typeMember(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  TypeMemberContext : public antlr4::ParserRuleContext {
  public:
    TypeMemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DecTypeContext *decType();
    antlr4::tree::TerminalNode *Identifier();
    FunctionContext *function();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeMemberContext* typeMember();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DecTypeContext *decType();
    antlr4::tree::TerminalNode *Identifier();
    FuncArgsContext *funcArgs();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  FuncArgsContext : public antlr4::ParserRuleContext {
  public:
    FuncArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FuncArgsContext* funcArgs();

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DecTypeContext *decType();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgContext* arg();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    DecTypeContext *decType();
    std::vector<DecVarContext *> decVar();
    DecVarContext* decVar(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *OAss();
    antlr4::tree::TerminalNode *OPlusPlus();
    antlr4::tree::TerminalNode *OMinusMinus();
    antlr4::tree::TerminalNode *Kreturn();
    antlr4::tree::TerminalNode *Kif();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    antlr4::tree::TerminalNode *Kelse();
    antlr4::tree::TerminalNode *Kwhile();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StmtContext* stmt();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  DecVarContext : public antlr4::ParserRuleContext {
  public:
    DecVarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *OAss();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DecVarContext* decVar();

  class  DecTypeContext : public antlr4::ParserRuleContext {
  public:
    DecTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    DecTypeContext *decType();
    antlr4::tree::TerminalNode *OArrBL();
    antlr4::tree::TerminalNode *OArrBR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DecTypeContext* decType();
  DecTypeContext* decType(int precedence);
  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Kint();
    antlr4::tree::TerminalNode *Kstring();
    antlr4::tree::TerminalNode *Kvoid();
    antlr4::tree::TerminalNode *Kbool();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeNameContext* typeName();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr7Context *expr7();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExprContext* expr();

  class  Expr7Context : public antlr4::ParserRuleContext {
  public:
    Expr7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr6Context *expr6();
    antlr4::tree::TerminalNode *OOr();
    Expr7Context *expr7();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr7Context* expr7();

  class  Expr6Context : public antlr4::ParserRuleContext {
  public:
    Expr6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr5Context *expr5();
    antlr4::tree::TerminalNode *OAnd();
    Expr6Context *expr6();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr6Context* expr6();

  class  Expr5Context : public antlr4::ParserRuleContext {
  public:
    Expr5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr4Context *expr4();
    Expr5Context *expr5();
    antlr4::tree::TerminalNode *OLT();
    antlr4::tree::TerminalNode *OLTE();
    antlr4::tree::TerminalNode *OGT();
    antlr4::tree::TerminalNode *OGTE();
    antlr4::tree::TerminalNode *OEq();
    antlr4::tree::TerminalNode *ONEq();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr5Context* expr5();
  Expr5Context* expr5(int precedence);
  class  Expr4Context : public antlr4::ParserRuleContext {
  public:
    Expr4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr3Context *expr3();
    Expr4Context *expr4();
    antlr4::tree::TerminalNode *OPlus();
    antlr4::tree::TerminalNode *OMinus();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr4Context* expr4();
  Expr4Context* expr4(int precedence);
  class  Expr3Context : public antlr4::ParserRuleContext {
  public:
    Expr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr2Context *expr2();
    Expr3Context *expr3();
    antlr4::tree::TerminalNode *OMul();
    antlr4::tree::TerminalNode *OMod();
    antlr4::tree::TerminalNode *ODiv();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr3Context* expr3();
  Expr3Context* expr3(int precedence);
  class  Expr2Context : public antlr4::ParserRuleContext {
  public:
    Expr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr1Context *expr1();
    Expr2Context *expr2();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *OArrBL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *OArrBR();
    CallListContext *callList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr2Context* expr2();
  Expr2Context* expr2(int precedence);
  class  Expr1Context : public antlr4::ParserRuleContext {
  public:
    Expr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr1IntConstantContext *expr1IntConstant();
    Expr1StringConstantContext *expr1StringConstant();
    Expr1VariableContext *expr1Variable();
    Expr1BoolConstantContext *expr1BoolConstant();
    Expr1MinusContext *expr1Minus();
    Expr1NotContext *expr1Not();
    Expr1ParContext *expr1Par();
    Expr1NewArrayContext *expr1NewArray();
    Expr1NewObjectContext *expr1NewObject();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1Context* expr1();

  class  Expr1IntConstantContext : public antlr4::ParserRuleContext {
  public:
    Expr1IntConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1IntConstantContext* expr1IntConstant();

  class  Expr1StringConstantContext : public antlr4::ParserRuleContext {
  public:
    Expr1StringConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1StringConstantContext* expr1StringConstant();

  class  Expr1BoolConstantContext : public antlr4::ParserRuleContext {
  public:
    Expr1BoolConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KFalse();
    antlr4::tree::TerminalNode *KTrue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1BoolConstantContext* expr1BoolConstant();

  class  Expr1VariableContext : public antlr4::ParserRuleContext {
  public:
    Expr1VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1VariableContext* expr1Variable();

  class  Expr1MinusContext : public antlr4::ParserRuleContext {
  public:
    Expr1MinusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OMinus();
    Expr1Context *expr1();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1MinusContext* expr1Minus();

  class  Expr1NotContext : public antlr4::ParserRuleContext {
  public:
    Expr1NotContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ONot();
    Expr1Context *expr1();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1NotContext* expr1Not();

  class  Expr1ParContext : public antlr4::ParserRuleContext {
  public:
    Expr1ParContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1ParContext* expr1Par();

  class  Expr1NewArrayContext : public antlr4::ParserRuleContext {
  public:
    Expr1NewArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Knew();
    DecTypeContext *decType();
    antlr4::tree::TerminalNode *OArrBL();
    ExprContext *expr();
    antlr4::tree::TerminalNode *OArrBR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1NewArrayContext* expr1NewArray();

  class  Expr1NewObjectContext : public antlr4::ParserRuleContext {
  public:
    Expr1NewObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Knew();
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expr1NewObjectContext* expr1NewObject();

  class  CallListContext : public antlr4::ParserRuleContext {
  public:
    CallListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallListContext* callList();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool decTypeSempred(DecTypeContext *_localctx, size_t predicateIndex);
  bool expr5Sempred(Expr5Context *_localctx, size_t predicateIndex);
  bool expr4Sempred(Expr4Context *_localctx, size_t predicateIndex);
  bool expr3Sempred(Expr3Context *_localctx, size_t predicateIndex);
  bool expr2Sempred(Expr2Context *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

