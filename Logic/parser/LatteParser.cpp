
// Generated from Latte.g4 by ANTLR 4.7.2


#include "LatteListener.h"

#include "LatteParser.h"


using namespace antlrcpp;
using namespace antlr4;

LatteParser::LatteParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LatteParser::~LatteParser() {
  delete _interpreter;
}

std::string LatteParser::getGrammarFileName() const {
  return "Latte.g4";
}

const std::vector<std::string>& LatteParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LatteParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainContext ------------------------------------------------------------------

LatteParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::MainContext::EOF() {
  return getToken(LatteParser::EOF, 0);
}

std::vector<LatteParser::TopDefContext *> LatteParser::MainContext::topDef() {
  return getRuleContexts<LatteParser::TopDefContext>();
}

LatteParser::TopDefContext* LatteParser::MainContext::topDef(size_t i) {
  return getRuleContext<LatteParser::TopDefContext>(i);
}


size_t LatteParser::MainContext::getRuleIndex() const {
  return LatteParser::RuleMain;
}

void LatteParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void LatteParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}

LatteParser::MainContext* LatteParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, LatteParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::Kclass)
      | (1ULL << LatteParser::Kint)
      | (1ULL << LatteParser::Kstring)
      | (1ULL << LatteParser::Kvoid)
      | (1ULL << LatteParser::Kbool)
      | (1ULL << LatteParser::Identifier))) != 0)) {
      setState(66);
      topDef();
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    match(LatteParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopDefContext ------------------------------------------------------------------

LatteParser::TopDefContext::TopDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::FunctionContext* LatteParser::TopDefContext::function() {
  return getRuleContext<LatteParser::FunctionContext>(0);
}

LatteParser::TypeContext* LatteParser::TopDefContext::type() {
  return getRuleContext<LatteParser::TypeContext>(0);
}


size_t LatteParser::TopDefContext::getRuleIndex() const {
  return LatteParser::RuleTopDef;
}

void LatteParser::TopDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTopDef(this);
}

void LatteParser::TopDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTopDef(this);
}

LatteParser::TopDefContext* LatteParser::topDef() {
  TopDefContext *_localctx = _tracker.createInstance<TopDefContext>(_ctx, getState());
  enterRule(_localctx, 2, LatteParser::RuleTopDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LatteParser::Kint:
      case LatteParser::Kstring:
      case LatteParser::Kvoid:
      case LatteParser::Kbool:
      case LatteParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        function();
        break;
      }

      case LatteParser::Kclass: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

LatteParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::TypeContext::Kclass() {
  return getToken(LatteParser::Kclass, 0);
}

tree::TerminalNode* LatteParser::TypeContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}

LatteParser::ExtendBlockContext* LatteParser::TypeContext::extendBlock() {
  return getRuleContext<LatteParser::ExtendBlockContext>(0);
}

std::vector<LatteParser::TypeMemberContext *> LatteParser::TypeContext::typeMember() {
  return getRuleContexts<LatteParser::TypeMemberContext>();
}

LatteParser::TypeMemberContext* LatteParser::TypeContext::typeMember(size_t i) {
  return getRuleContext<LatteParser::TypeMemberContext>(i);
}


size_t LatteParser::TypeContext::getRuleIndex() const {
  return LatteParser::RuleType;
}

void LatteParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void LatteParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

LatteParser::TypeContext* LatteParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, LatteParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(LatteParser::Kclass);
    setState(79);
    match(LatteParser::Identifier);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == LatteParser::Kextends) {
      setState(80);
      extendBlock();
    }
    setState(83);
    match(LatteParser::T__0);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::Kint)
      | (1ULL << LatteParser::Kstring)
      | (1ULL << LatteParser::Kvoid)
      | (1ULL << LatteParser::Kbool)
      | (1ULL << LatteParser::Identifier))) != 0)) {
      setState(84);
      typeMember();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(LatteParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExtendBlockContext ------------------------------------------------------------------

LatteParser::ExtendBlockContext::ExtendBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::ExtendBlockContext::Kextends() {
  return getToken(LatteParser::Kextends, 0);
}

tree::TerminalNode* LatteParser::ExtendBlockContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}


size_t LatteParser::ExtendBlockContext::getRuleIndex() const {
  return LatteParser::RuleExtendBlock;
}

void LatteParser::ExtendBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtendBlock(this);
}

void LatteParser::ExtendBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtendBlock(this);
}

LatteParser::ExtendBlockContext* LatteParser::extendBlock() {
  ExtendBlockContext *_localctx = _tracker.createInstance<ExtendBlockContext>(_ctx, getState());
  enterRule(_localctx, 6, LatteParser::RuleExtendBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(LatteParser::Kextends);
    setState(93);
    match(LatteParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeMemberContext ------------------------------------------------------------------

LatteParser::TypeMemberContext::TypeMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::TypeVarContext* LatteParser::TypeMemberContext::typeVar() {
  return getRuleContext<LatteParser::TypeVarContext>(0);
}

LatteParser::FunctionContext* LatteParser::TypeMemberContext::function() {
  return getRuleContext<LatteParser::FunctionContext>(0);
}


size_t LatteParser::TypeMemberContext::getRuleIndex() const {
  return LatteParser::RuleTypeMember;
}

void LatteParser::TypeMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeMember(this);
}

void LatteParser::TypeMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeMember(this);
}

LatteParser::TypeMemberContext* LatteParser::typeMember() {
  TypeMemberContext *_localctx = _tracker.createInstance<TypeMemberContext>(_ctx, getState());
  enterRule(_localctx, 8, LatteParser::RuleTypeMember);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(95);
      typeVar();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      function();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeVarContext ------------------------------------------------------------------

LatteParser::TypeVarContext::TypeVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::DecTypeContext* LatteParser::TypeVarContext::decType() {
  return getRuleContext<LatteParser::DecTypeContext>(0);
}

tree::TerminalNode* LatteParser::TypeVarContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}


size_t LatteParser::TypeVarContext::getRuleIndex() const {
  return LatteParser::RuleTypeVar;
}

void LatteParser::TypeVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeVar(this);
}

void LatteParser::TypeVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeVar(this);
}

LatteParser::TypeVarContext* LatteParser::typeVar() {
  TypeVarContext *_localctx = _tracker.createInstance<TypeVarContext>(_ctx, getState());
  enterRule(_localctx, 10, LatteParser::RuleTypeVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    decType(0);
    setState(100);
    match(LatteParser::Identifier);
    setState(101);
    match(LatteParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

LatteParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::DecTypeContext* LatteParser::FunctionContext::decType() {
  return getRuleContext<LatteParser::DecTypeContext>(0);
}

tree::TerminalNode* LatteParser::FunctionContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}

LatteParser::FuncArgsContext* LatteParser::FunctionContext::funcArgs() {
  return getRuleContext<LatteParser::FuncArgsContext>(0);
}

LatteParser::BlockContext* LatteParser::FunctionContext::block() {
  return getRuleContext<LatteParser::BlockContext>(0);
}


size_t LatteParser::FunctionContext::getRuleIndex() const {
  return LatteParser::RuleFunction;
}

void LatteParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void LatteParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

LatteParser::FunctionContext* LatteParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 12, LatteParser::RuleFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    decType(0);
    setState(104);
    match(LatteParser::Identifier);
    setState(105);
    funcArgs();
    setState(106);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncArgsContext ------------------------------------------------------------------

LatteParser::FuncArgsContext::FuncArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::FuncArgsContext::ParBL() {
  return getToken(LatteParser::ParBL, 0);
}

tree::TerminalNode* LatteParser::FuncArgsContext::ParBR() {
  return getToken(LatteParser::ParBR, 0);
}

std::vector<LatteParser::ArgContext *> LatteParser::FuncArgsContext::arg() {
  return getRuleContexts<LatteParser::ArgContext>();
}

LatteParser::ArgContext* LatteParser::FuncArgsContext::arg(size_t i) {
  return getRuleContext<LatteParser::ArgContext>(i);
}


size_t LatteParser::FuncArgsContext::getRuleIndex() const {
  return LatteParser::RuleFuncArgs;
}

void LatteParser::FuncArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncArgs(this);
}

void LatteParser::FuncArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncArgs(this);
}

LatteParser::FuncArgsContext* LatteParser::funcArgs() {
  FuncArgsContext *_localctx = _tracker.createInstance<FuncArgsContext>(_ctx, getState());
  enterRule(_localctx, 14, LatteParser::RuleFuncArgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      match(LatteParser::ParBL);
      setState(109);
      match(LatteParser::ParBR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(110);
      match(LatteParser::ParBL);
      setState(111);
      arg();
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LatteParser::T__3) {
        setState(112);
        match(LatteParser::T__3);
        setState(113);
        arg();
        setState(118);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(119);
      match(LatteParser::ParBR);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

LatteParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::DecTypeContext* LatteParser::ArgContext::decType() {
  return getRuleContext<LatteParser::DecTypeContext>(0);
}

tree::TerminalNode* LatteParser::ArgContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}


size_t LatteParser::ArgContext::getRuleIndex() const {
  return LatteParser::RuleArg;
}

void LatteParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void LatteParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}

LatteParser::ArgContext* LatteParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 16, LatteParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    decType(0);
    setState(124);
    match(LatteParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

LatteParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::BlockContext* LatteParser::StmtContext::block() {
  return getRuleContext<LatteParser::BlockContext>(0);
}

LatteParser::DecTypeContext* LatteParser::StmtContext::decType() {
  return getRuleContext<LatteParser::DecTypeContext>(0);
}

std::vector<LatteParser::DecVarContext *> LatteParser::StmtContext::decVar() {
  return getRuleContexts<LatteParser::DecVarContext>();
}

LatteParser::DecVarContext* LatteParser::StmtContext::decVar(size_t i) {
  return getRuleContext<LatteParser::DecVarContext>(i);
}

std::vector<LatteParser::ExprContext *> LatteParser::StmtContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::StmtContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}

tree::TerminalNode* LatteParser::StmtContext::OAss() {
  return getToken(LatteParser::OAss, 0);
}

tree::TerminalNode* LatteParser::StmtContext::OPlusPlus() {
  return getToken(LatteParser::OPlusPlus, 0);
}

tree::TerminalNode* LatteParser::StmtContext::OMinusMinus() {
  return getToken(LatteParser::OMinusMinus, 0);
}

tree::TerminalNode* LatteParser::StmtContext::Kreturn() {
  return getToken(LatteParser::Kreturn, 0);
}

tree::TerminalNode* LatteParser::StmtContext::Kif() {
  return getToken(LatteParser::Kif, 0);
}

tree::TerminalNode* LatteParser::StmtContext::ParBL() {
  return getToken(LatteParser::ParBL, 0);
}

tree::TerminalNode* LatteParser::StmtContext::ParBR() {
  return getToken(LatteParser::ParBR, 0);
}

std::vector<LatteParser::StmtContext *> LatteParser::StmtContext::stmt() {
  return getRuleContexts<LatteParser::StmtContext>();
}

LatteParser::StmtContext* LatteParser::StmtContext::stmt(size_t i) {
  return getRuleContext<LatteParser::StmtContext>(i);
}

tree::TerminalNode* LatteParser::StmtContext::Kelse() {
  return getToken(LatteParser::Kelse, 0);
}

tree::TerminalNode* LatteParser::StmtContext::Kwhile() {
  return getToken(LatteParser::Kwhile, 0);
}


size_t LatteParser::StmtContext::getRuleIndex() const {
  return LatteParser::RuleStmt;
}

void LatteParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void LatteParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

LatteParser::StmtContext* LatteParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 18, LatteParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(126);
      match(LatteParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(127);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(128);
      decType(0);
      setState(129);
      decVar();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == LatteParser::T__3) {
        setState(130);
        match(LatteParser::T__3);
        setState(131);
        decVar();
        setState(136);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(137);
      match(LatteParser::T__2);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(139);
      expr();
      setState(140);
      match(LatteParser::OAss);
      setState(141);
      expr();
      setState(142);
      match(LatteParser::T__2);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(144);
      expr();
      setState(145);
      match(LatteParser::OPlusPlus);
      setState(146);
      match(LatteParser::T__2);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(148);
      expr();
      setState(149);
      match(LatteParser::OMinusMinus);
      setState(150);
      match(LatteParser::T__2);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(152);
      match(LatteParser::Kreturn);
      setState(153);
      expr();
      setState(154);
      match(LatteParser::T__2);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(156);
      match(LatteParser::Kreturn);
      setState(157);
      match(LatteParser::T__2);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(158);
      match(LatteParser::Kif);
      setState(159);
      match(LatteParser::ParBL);
      setState(160);
      expr();
      setState(161);
      match(LatteParser::ParBR);
      setState(162);
      stmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(164);
      match(LatteParser::Kif);
      setState(165);
      match(LatteParser::ParBL);
      setState(166);
      expr();
      setState(167);
      match(LatteParser::ParBR);
      setState(168);
      stmt();
      setState(169);
      match(LatteParser::Kelse);
      setState(170);
      stmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(172);
      match(LatteParser::Kwhile);
      setState(173);
      match(LatteParser::ParBL);
      setState(174);
      expr();
      setState(175);
      match(LatteParser::ParBR);
      setState(176);
      stmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(178);
      expr();
      setState(179);
      match(LatteParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

LatteParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LatteParser::StmtContext *> LatteParser::BlockContext::stmt() {
  return getRuleContexts<LatteParser::StmtContext>();
}

LatteParser::StmtContext* LatteParser::BlockContext::stmt(size_t i) {
  return getRuleContext<LatteParser::StmtContext>(i);
}


size_t LatteParser::BlockContext::getRuleIndex() const {
  return LatteParser::RuleBlock;
}

void LatteParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void LatteParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

LatteParser::BlockContext* LatteParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, LatteParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(LatteParser::T__0);
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::T__0)
      | (1ULL << LatteParser::T__2)
      | (1ULL << LatteParser::OMinus)
      | (1ULL << LatteParser::ONot)
      | (1ULL << LatteParser::ParBL)
      | (1ULL << LatteParser::Kreturn)
      | (1ULL << LatteParser::Kwhile)
      | (1ULL << LatteParser::Kif)
      | (1ULL << LatteParser::Knew)
      | (1ULL << LatteParser::Kint)
      | (1ULL << LatteParser::Kstring)
      | (1ULL << LatteParser::Kvoid)
      | (1ULL << LatteParser::Kbool)
      | (1ULL << LatteParser::KTrue)
      | (1ULL << LatteParser::KFalse)
      | (1ULL << LatteParser::Identifier)
      | (1ULL << LatteParser::IntLiteral)
      | (1ULL << LatteParser::StringLiteral))) != 0)) {
      setState(184);
      stmt();
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(190);
    match(LatteParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecVarContext ------------------------------------------------------------------

LatteParser::DecVarContext::DecVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::DecVarContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}

tree::TerminalNode* LatteParser::DecVarContext::OAss() {
  return getToken(LatteParser::OAss, 0);
}

LatteParser::ExprContext* LatteParser::DecVarContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}


size_t LatteParser::DecVarContext::getRuleIndex() const {
  return LatteParser::RuleDecVar;
}

void LatteParser::DecVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecVar(this);
}

void LatteParser::DecVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecVar(this);
}

LatteParser::DecVarContext* LatteParser::decVar() {
  DecVarContext *_localctx = _tracker.createInstance<DecVarContext>(_ctx, getState());
  enterRule(_localctx, 22, LatteParser::RuleDecVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      match(LatteParser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(193);
      match(LatteParser::Identifier);
      setState(194);
      match(LatteParser::OAss);
      setState(195);
      expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecTypeContext ------------------------------------------------------------------

LatteParser::DecTypeContext::DecTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::TypeNameContext* LatteParser::DecTypeContext::typeName() {
  return getRuleContext<LatteParser::TypeNameContext>(0);
}

LatteParser::DecTypeContext* LatteParser::DecTypeContext::decType() {
  return getRuleContext<LatteParser::DecTypeContext>(0);
}

tree::TerminalNode* LatteParser::DecTypeContext::OArrBL() {
  return getToken(LatteParser::OArrBL, 0);
}

tree::TerminalNode* LatteParser::DecTypeContext::OArrBR() {
  return getToken(LatteParser::OArrBR, 0);
}


size_t LatteParser::DecTypeContext::getRuleIndex() const {
  return LatteParser::RuleDecType;
}

void LatteParser::DecTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecType(this);
}

void LatteParser::DecTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecType(this);
}


LatteParser::DecTypeContext* LatteParser::decType() {
   return decType(0);
}

LatteParser::DecTypeContext* LatteParser::decType(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::DecTypeContext *_localctx = _tracker.createInstance<DecTypeContext>(_ctx, parentState);
  LatteParser::DecTypeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, LatteParser::RuleDecType, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(199);
    typeName();
    _ctx->stop = _input->LT(-1);
    setState(206);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<DecTypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleDecType);
        setState(201);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(202);
        match(LatteParser::OArrBL);
        setState(203);
        match(LatteParser::OArrBR); 
      }
      setState(208);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

LatteParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::TypeNameContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}

tree::TerminalNode* LatteParser::TypeNameContext::Kint() {
  return getToken(LatteParser::Kint, 0);
}

tree::TerminalNode* LatteParser::TypeNameContext::Kstring() {
  return getToken(LatteParser::Kstring, 0);
}

tree::TerminalNode* LatteParser::TypeNameContext::Kvoid() {
  return getToken(LatteParser::Kvoid, 0);
}

tree::TerminalNode* LatteParser::TypeNameContext::Kbool() {
  return getToken(LatteParser::Kbool, 0);
}


size_t LatteParser::TypeNameContext::getRuleIndex() const {
  return LatteParser::RuleTypeName;
}

void LatteParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void LatteParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}

LatteParser::TypeNameContext* LatteParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 26, LatteParser::RuleTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LatteParser::Kint)
      | (1ULL << LatteParser::Kstring)
      | (1ULL << LatteParser::Kvoid)
      | (1ULL << LatteParser::Kbool)
      | (1ULL << LatteParser::Identifier))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

LatteParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr7Context* LatteParser::ExprContext::expr7() {
  return getRuleContext<LatteParser::Expr7Context>(0);
}


size_t LatteParser::ExprContext::getRuleIndex() const {
  return LatteParser::RuleExpr;
}

void LatteParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void LatteParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

LatteParser::ExprContext* LatteParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 28, LatteParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    expr7();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr7Context ------------------------------------------------------------------

LatteParser::Expr7Context::Expr7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr6Context* LatteParser::Expr7Context::expr6() {
  return getRuleContext<LatteParser::Expr6Context>(0);
}

tree::TerminalNode* LatteParser::Expr7Context::OOr() {
  return getToken(LatteParser::OOr, 0);
}

LatteParser::Expr7Context* LatteParser::Expr7Context::expr7() {
  return getRuleContext<LatteParser::Expr7Context>(0);
}


size_t LatteParser::Expr7Context::getRuleIndex() const {
  return LatteParser::RuleExpr7;
}

void LatteParser::Expr7Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr7(this);
}

void LatteParser::Expr7Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr7(this);
}

LatteParser::Expr7Context* LatteParser::expr7() {
  Expr7Context *_localctx = _tracker.createInstance<Expr7Context>(_ctx, getState());
  enterRule(_localctx, 30, LatteParser::RuleExpr7);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(218);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(213);
      expr6();
      setState(214);
      match(LatteParser::OOr);
      setState(215);
      expr7();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(217);
      expr6();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr6Context ------------------------------------------------------------------

LatteParser::Expr6Context::Expr6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr5Context* LatteParser::Expr6Context::expr5() {
  return getRuleContext<LatteParser::Expr5Context>(0);
}

tree::TerminalNode* LatteParser::Expr6Context::OAnd() {
  return getToken(LatteParser::OAnd, 0);
}

LatteParser::Expr6Context* LatteParser::Expr6Context::expr6() {
  return getRuleContext<LatteParser::Expr6Context>(0);
}


size_t LatteParser::Expr6Context::getRuleIndex() const {
  return LatteParser::RuleExpr6;
}

void LatteParser::Expr6Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr6(this);
}

void LatteParser::Expr6Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr6(this);
}

LatteParser::Expr6Context* LatteParser::expr6() {
  Expr6Context *_localctx = _tracker.createInstance<Expr6Context>(_ctx, getState());
  enterRule(_localctx, 32, LatteParser::RuleExpr6);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(220);
      expr5(0);
      setState(221);
      match(LatteParser::OAnd);
      setState(222);
      expr6();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(224);
      expr5(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr5Context ------------------------------------------------------------------

LatteParser::Expr5Context::Expr5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr4Context* LatteParser::Expr5Context::expr4() {
  return getRuleContext<LatteParser::Expr4Context>(0);
}

LatteParser::Expr5Context* LatteParser::Expr5Context::expr5() {
  return getRuleContext<LatteParser::Expr5Context>(0);
}

tree::TerminalNode* LatteParser::Expr5Context::OLT() {
  return getToken(LatteParser::OLT, 0);
}

tree::TerminalNode* LatteParser::Expr5Context::OLTE() {
  return getToken(LatteParser::OLTE, 0);
}

tree::TerminalNode* LatteParser::Expr5Context::OGT() {
  return getToken(LatteParser::OGT, 0);
}

tree::TerminalNode* LatteParser::Expr5Context::OGTE() {
  return getToken(LatteParser::OGTE, 0);
}

tree::TerminalNode* LatteParser::Expr5Context::OEq() {
  return getToken(LatteParser::OEq, 0);
}

tree::TerminalNode* LatteParser::Expr5Context::ONEq() {
  return getToken(LatteParser::ONEq, 0);
}


size_t LatteParser::Expr5Context::getRuleIndex() const {
  return LatteParser::RuleExpr5;
}

void LatteParser::Expr5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr5(this);
}

void LatteParser::Expr5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr5(this);
}


LatteParser::Expr5Context* LatteParser::expr5() {
   return expr5(0);
}

LatteParser::Expr5Context* LatteParser::expr5(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::Expr5Context *_localctx = _tracker.createInstance<Expr5Context>(_ctx, parentState);
  LatteParser::Expr5Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, LatteParser::RuleExpr5, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(228);
    expr4(0);
    _ctx->stop = _input->LT(-1);
    setState(250);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(248);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Expr5Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr5);
          setState(230);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(231);
          match(LatteParser::OLT);
          setState(232);
          expr4(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Expr5Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr5);
          setState(233);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(234);
          match(LatteParser::OLTE);
          setState(235);
          expr4(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Expr5Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr5);
          setState(236);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(237);
          match(LatteParser::OGT);
          setState(238);
          expr4(0);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<Expr5Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr5);
          setState(239);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(240);
          match(LatteParser::OGTE);
          setState(241);
          expr4(0);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<Expr5Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr5);
          setState(242);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(243);
          match(LatteParser::OEq);
          setState(244);
          expr4(0);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<Expr5Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr5);
          setState(245);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(246);
          match(LatteParser::ONEq);
          setState(247);
          expr4(0);
          break;
        }

        } 
      }
      setState(252);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr4Context ------------------------------------------------------------------

LatteParser::Expr4Context::Expr4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr3Context* LatteParser::Expr4Context::expr3() {
  return getRuleContext<LatteParser::Expr3Context>(0);
}

LatteParser::Expr4Context* LatteParser::Expr4Context::expr4() {
  return getRuleContext<LatteParser::Expr4Context>(0);
}

tree::TerminalNode* LatteParser::Expr4Context::OPlus() {
  return getToken(LatteParser::OPlus, 0);
}

tree::TerminalNode* LatteParser::Expr4Context::OMinus() {
  return getToken(LatteParser::OMinus, 0);
}


size_t LatteParser::Expr4Context::getRuleIndex() const {
  return LatteParser::RuleExpr4;
}

void LatteParser::Expr4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr4(this);
}

void LatteParser::Expr4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr4(this);
}


LatteParser::Expr4Context* LatteParser::expr4() {
   return expr4(0);
}

LatteParser::Expr4Context* LatteParser::expr4(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::Expr4Context *_localctx = _tracker.createInstance<Expr4Context>(_ctx, parentState);
  LatteParser::Expr4Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, LatteParser::RuleExpr4, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(254);
    expr3(0);
    _ctx->stop = _input->LT(-1);
    setState(264);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(262);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Expr4Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr4);
          setState(256);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(257);
          match(LatteParser::OPlus);
          setState(258);
          expr3(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Expr4Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr4);
          setState(259);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(260);
          match(LatteParser::OMinus);
          setState(261);
          expr3(0);
          break;
        }

        } 
      }
      setState(266);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr3Context ------------------------------------------------------------------

LatteParser::Expr3Context::Expr3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr2Context* LatteParser::Expr3Context::expr2() {
  return getRuleContext<LatteParser::Expr2Context>(0);
}

LatteParser::Expr3Context* LatteParser::Expr3Context::expr3() {
  return getRuleContext<LatteParser::Expr3Context>(0);
}

tree::TerminalNode* LatteParser::Expr3Context::OMul() {
  return getToken(LatteParser::OMul, 0);
}

tree::TerminalNode* LatteParser::Expr3Context::OMod() {
  return getToken(LatteParser::OMod, 0);
}

tree::TerminalNode* LatteParser::Expr3Context::ODiv() {
  return getToken(LatteParser::ODiv, 0);
}


size_t LatteParser::Expr3Context::getRuleIndex() const {
  return LatteParser::RuleExpr3;
}

void LatteParser::Expr3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr3(this);
}

void LatteParser::Expr3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr3(this);
}


LatteParser::Expr3Context* LatteParser::expr3() {
   return expr3(0);
}

LatteParser::Expr3Context* LatteParser::expr3(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::Expr3Context *_localctx = _tracker.createInstance<Expr3Context>(_ctx, parentState);
  LatteParser::Expr3Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, LatteParser::RuleExpr3, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(268);
    expr2(0);
    _ctx->stop = _input->LT(-1);
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(279);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Expr3Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr3);
          setState(270);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(271);
          match(LatteParser::OMul);
          setState(272);
          expr2(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Expr3Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr3);
          setState(273);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(274);
          match(LatteParser::OMod);
          setState(275);
          expr2(0);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Expr3Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr3);
          setState(276);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(277);
          match(LatteParser::ODiv);
          setState(278);
          expr2(0);
          break;
        }

        } 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr2Context ------------------------------------------------------------------

LatteParser::Expr2Context::Expr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr1Context* LatteParser::Expr2Context::expr1() {
  return getRuleContext<LatteParser::Expr1Context>(0);
}

LatteParser::Expr2Context* LatteParser::Expr2Context::expr2() {
  return getRuleContext<LatteParser::Expr2Context>(0);
}

tree::TerminalNode* LatteParser::Expr2Context::Dot() {
  return getToken(LatteParser::Dot, 0);
}

tree::TerminalNode* LatteParser::Expr2Context::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}

tree::TerminalNode* LatteParser::Expr2Context::OArrBL() {
  return getToken(LatteParser::OArrBL, 0);
}

LatteParser::ExprContext* LatteParser::Expr2Context::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

tree::TerminalNode* LatteParser::Expr2Context::OArrBR() {
  return getToken(LatteParser::OArrBR, 0);
}

tree::TerminalNode* LatteParser::Expr2Context::ParBL() {
  return getToken(LatteParser::ParBL, 0);
}

tree::TerminalNode* LatteParser::Expr2Context::ParBR() {
  return getToken(LatteParser::ParBR, 0);
}

LatteParser::CallListContext* LatteParser::Expr2Context::callList() {
  return getRuleContext<LatteParser::CallListContext>(0);
}


size_t LatteParser::Expr2Context::getRuleIndex() const {
  return LatteParser::RuleExpr2;
}

void LatteParser::Expr2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr2(this);
}

void LatteParser::Expr2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr2(this);
}


LatteParser::Expr2Context* LatteParser::expr2() {
   return expr2(0);
}

LatteParser::Expr2Context* LatteParser::expr2(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LatteParser::Expr2Context *_localctx = _tracker.createInstance<Expr2Context>(_ctx, parentState);
  LatteParser::Expr2Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, LatteParser::RuleExpr2, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(285);
    expr1();
    _ctx->stop = _input->LT(-1);
    setState(303);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(301);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Expr2Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr2);
          setState(287);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(288);
          match(LatteParser::Dot);
          setState(289);
          match(LatteParser::Identifier);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Expr2Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr2);
          setState(290);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(291);
          match(LatteParser::OArrBL);
          setState(292);
          expr();
          setState(293);
          match(LatteParser::OArrBR);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Expr2Context>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr2);
          setState(295);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(296);
          match(LatteParser::ParBL);
          setState(298);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << LatteParser::OMinus)
            | (1ULL << LatteParser::ONot)
            | (1ULL << LatteParser::ParBL)
            | (1ULL << LatteParser::Knew)
            | (1ULL << LatteParser::KTrue)
            | (1ULL << LatteParser::KFalse)
            | (1ULL << LatteParser::Identifier)
            | (1ULL << LatteParser::IntLiteral)
            | (1ULL << LatteParser::StringLiteral))) != 0)) {
            setState(297);
            callList();
          }
          setState(300);
          match(LatteParser::ParBR);
          break;
        }

        } 
      }
      setState(305);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr1Context ------------------------------------------------------------------

LatteParser::Expr1Context::Expr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LatteParser::Expr1IntConstantContext* LatteParser::Expr1Context::expr1IntConstant() {
  return getRuleContext<LatteParser::Expr1IntConstantContext>(0);
}

LatteParser::Expr1StringConstantContext* LatteParser::Expr1Context::expr1StringConstant() {
  return getRuleContext<LatteParser::Expr1StringConstantContext>(0);
}

LatteParser::Expr1VariableContext* LatteParser::Expr1Context::expr1Variable() {
  return getRuleContext<LatteParser::Expr1VariableContext>(0);
}

LatteParser::Expr1BoolConstantContext* LatteParser::Expr1Context::expr1BoolConstant() {
  return getRuleContext<LatteParser::Expr1BoolConstantContext>(0);
}

LatteParser::Expr1MinusContext* LatteParser::Expr1Context::expr1Minus() {
  return getRuleContext<LatteParser::Expr1MinusContext>(0);
}

LatteParser::Expr1NotContext* LatteParser::Expr1Context::expr1Not() {
  return getRuleContext<LatteParser::Expr1NotContext>(0);
}

LatteParser::Expr1ParContext* LatteParser::Expr1Context::expr1Par() {
  return getRuleContext<LatteParser::Expr1ParContext>(0);
}

LatteParser::Expr1NewArrayContext* LatteParser::Expr1Context::expr1NewArray() {
  return getRuleContext<LatteParser::Expr1NewArrayContext>(0);
}

LatteParser::Expr1NewObjectContext* LatteParser::Expr1Context::expr1NewObject() {
  return getRuleContext<LatteParser::Expr1NewObjectContext>(0);
}

LatteParser::Expr1NullContext* LatteParser::Expr1Context::expr1Null() {
  return getRuleContext<LatteParser::Expr1NullContext>(0);
}


size_t LatteParser::Expr1Context::getRuleIndex() const {
  return LatteParser::RuleExpr1;
}

void LatteParser::Expr1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1(this);
}

void LatteParser::Expr1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1(this);
}

LatteParser::Expr1Context* LatteParser::expr1() {
  Expr1Context *_localctx = _tracker.createInstance<Expr1Context>(_ctx, getState());
  enterRule(_localctx, 42, LatteParser::RuleExpr1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(316);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(306);
      expr1IntConstant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(307);
      expr1StringConstant();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(308);
      expr1Variable();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(309);
      expr1BoolConstant();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(310);
      expr1Minus();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(311);
      expr1Not();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(312);
      expr1Par();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(313);
      expr1NewArray();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(314);
      expr1NewObject();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(315);
      expr1Null();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1IntConstantContext ------------------------------------------------------------------

LatteParser::Expr1IntConstantContext::Expr1IntConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1IntConstantContext::IntLiteral() {
  return getToken(LatteParser::IntLiteral, 0);
}


size_t LatteParser::Expr1IntConstantContext::getRuleIndex() const {
  return LatteParser::RuleExpr1IntConstant;
}

void LatteParser::Expr1IntConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1IntConstant(this);
}

void LatteParser::Expr1IntConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1IntConstant(this);
}

LatteParser::Expr1IntConstantContext* LatteParser::expr1IntConstant() {
  Expr1IntConstantContext *_localctx = _tracker.createInstance<Expr1IntConstantContext>(_ctx, getState());
  enterRule(_localctx, 44, LatteParser::RuleExpr1IntConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    match(LatteParser::IntLiteral);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1StringConstantContext ------------------------------------------------------------------

LatteParser::Expr1StringConstantContext::Expr1StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1StringConstantContext::StringLiteral() {
  return getToken(LatteParser::StringLiteral, 0);
}


size_t LatteParser::Expr1StringConstantContext::getRuleIndex() const {
  return LatteParser::RuleExpr1StringConstant;
}

void LatteParser::Expr1StringConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1StringConstant(this);
}

void LatteParser::Expr1StringConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1StringConstant(this);
}

LatteParser::Expr1StringConstantContext* LatteParser::expr1StringConstant() {
  Expr1StringConstantContext *_localctx = _tracker.createInstance<Expr1StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 46, LatteParser::RuleExpr1StringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(320);
    match(LatteParser::StringLiteral);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1BoolConstantContext ------------------------------------------------------------------

LatteParser::Expr1BoolConstantContext::Expr1BoolConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1BoolConstantContext::KFalse() {
  return getToken(LatteParser::KFalse, 0);
}

tree::TerminalNode* LatteParser::Expr1BoolConstantContext::KTrue() {
  return getToken(LatteParser::KTrue, 0);
}


size_t LatteParser::Expr1BoolConstantContext::getRuleIndex() const {
  return LatteParser::RuleExpr1BoolConstant;
}

void LatteParser::Expr1BoolConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1BoolConstant(this);
}

void LatteParser::Expr1BoolConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1BoolConstant(this);
}

LatteParser::Expr1BoolConstantContext* LatteParser::expr1BoolConstant() {
  Expr1BoolConstantContext *_localctx = _tracker.createInstance<Expr1BoolConstantContext>(_ctx, getState());
  enterRule(_localctx, 48, LatteParser::RuleExpr1BoolConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    _la = _input->LA(1);
    if (!(_la == LatteParser::KTrue

    || _la == LatteParser::KFalse)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1VariableContext ------------------------------------------------------------------

LatteParser::Expr1VariableContext::Expr1VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1VariableContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}


size_t LatteParser::Expr1VariableContext::getRuleIndex() const {
  return LatteParser::RuleExpr1Variable;
}

void LatteParser::Expr1VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1Variable(this);
}

void LatteParser::Expr1VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1Variable(this);
}

LatteParser::Expr1VariableContext* LatteParser::expr1Variable() {
  Expr1VariableContext *_localctx = _tracker.createInstance<Expr1VariableContext>(_ctx, getState());
  enterRule(_localctx, 50, LatteParser::RuleExpr1Variable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(LatteParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1MinusContext ------------------------------------------------------------------

LatteParser::Expr1MinusContext::Expr1MinusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1MinusContext::OMinus() {
  return getToken(LatteParser::OMinus, 0);
}

LatteParser::Expr1Context* LatteParser::Expr1MinusContext::expr1() {
  return getRuleContext<LatteParser::Expr1Context>(0);
}


size_t LatteParser::Expr1MinusContext::getRuleIndex() const {
  return LatteParser::RuleExpr1Minus;
}

void LatteParser::Expr1MinusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1Minus(this);
}

void LatteParser::Expr1MinusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1Minus(this);
}

LatteParser::Expr1MinusContext* LatteParser::expr1Minus() {
  Expr1MinusContext *_localctx = _tracker.createInstance<Expr1MinusContext>(_ctx, getState());
  enterRule(_localctx, 52, LatteParser::RuleExpr1Minus);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    match(LatteParser::OMinus);
    setState(327);
    expr1();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1NotContext ------------------------------------------------------------------

LatteParser::Expr1NotContext::Expr1NotContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1NotContext::ONot() {
  return getToken(LatteParser::ONot, 0);
}

LatteParser::Expr1Context* LatteParser::Expr1NotContext::expr1() {
  return getRuleContext<LatteParser::Expr1Context>(0);
}


size_t LatteParser::Expr1NotContext::getRuleIndex() const {
  return LatteParser::RuleExpr1Not;
}

void LatteParser::Expr1NotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1Not(this);
}

void LatteParser::Expr1NotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1Not(this);
}

LatteParser::Expr1NotContext* LatteParser::expr1Not() {
  Expr1NotContext *_localctx = _tracker.createInstance<Expr1NotContext>(_ctx, getState());
  enterRule(_localctx, 54, LatteParser::RuleExpr1Not);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    match(LatteParser::ONot);
    setState(330);
    expr1();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1ParContext ------------------------------------------------------------------

LatteParser::Expr1ParContext::Expr1ParContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1ParContext::ParBL() {
  return getToken(LatteParser::ParBL, 0);
}

LatteParser::ExprContext* LatteParser::Expr1ParContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

tree::TerminalNode* LatteParser::Expr1ParContext::ParBR() {
  return getToken(LatteParser::ParBR, 0);
}


size_t LatteParser::Expr1ParContext::getRuleIndex() const {
  return LatteParser::RuleExpr1Par;
}

void LatteParser::Expr1ParContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1Par(this);
}

void LatteParser::Expr1ParContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1Par(this);
}

LatteParser::Expr1ParContext* LatteParser::expr1Par() {
  Expr1ParContext *_localctx = _tracker.createInstance<Expr1ParContext>(_ctx, getState());
  enterRule(_localctx, 56, LatteParser::RuleExpr1Par);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(LatteParser::ParBL);
    setState(333);
    expr();
    setState(334);
    match(LatteParser::ParBR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1NewArrayContext ------------------------------------------------------------------

LatteParser::Expr1NewArrayContext::Expr1NewArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1NewArrayContext::Knew() {
  return getToken(LatteParser::Knew, 0);
}

LatteParser::DecTypeContext* LatteParser::Expr1NewArrayContext::decType() {
  return getRuleContext<LatteParser::DecTypeContext>(0);
}

tree::TerminalNode* LatteParser::Expr1NewArrayContext::OArrBL() {
  return getToken(LatteParser::OArrBL, 0);
}

LatteParser::ExprContext* LatteParser::Expr1NewArrayContext::expr() {
  return getRuleContext<LatteParser::ExprContext>(0);
}

tree::TerminalNode* LatteParser::Expr1NewArrayContext::OArrBR() {
  return getToken(LatteParser::OArrBR, 0);
}


size_t LatteParser::Expr1NewArrayContext::getRuleIndex() const {
  return LatteParser::RuleExpr1NewArray;
}

void LatteParser::Expr1NewArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1NewArray(this);
}

void LatteParser::Expr1NewArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1NewArray(this);
}

LatteParser::Expr1NewArrayContext* LatteParser::expr1NewArray() {
  Expr1NewArrayContext *_localctx = _tracker.createInstance<Expr1NewArrayContext>(_ctx, getState());
  enterRule(_localctx, 58, LatteParser::RuleExpr1NewArray);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(LatteParser::Knew);
    setState(337);
    decType(0);
    setState(338);
    match(LatteParser::OArrBL);
    setState(339);
    expr();
    setState(340);
    match(LatteParser::OArrBR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1NewObjectContext ------------------------------------------------------------------

LatteParser::Expr1NewObjectContext::Expr1NewObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1NewObjectContext::Knew() {
  return getToken(LatteParser::Knew, 0);
}

tree::TerminalNode* LatteParser::Expr1NewObjectContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}


size_t LatteParser::Expr1NewObjectContext::getRuleIndex() const {
  return LatteParser::RuleExpr1NewObject;
}

void LatteParser::Expr1NewObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1NewObject(this);
}

void LatteParser::Expr1NewObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1NewObject(this);
}

LatteParser::Expr1NewObjectContext* LatteParser::expr1NewObject() {
  Expr1NewObjectContext *_localctx = _tracker.createInstance<Expr1NewObjectContext>(_ctx, getState());
  enterRule(_localctx, 60, LatteParser::RuleExpr1NewObject);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(LatteParser::Knew);
    setState(343);
    match(LatteParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr1NullContext ------------------------------------------------------------------

LatteParser::Expr1NullContext::Expr1NullContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LatteParser::Expr1NullContext::ParBL() {
  return getToken(LatteParser::ParBL, 0);
}

tree::TerminalNode* LatteParser::Expr1NullContext::Identifier() {
  return getToken(LatteParser::Identifier, 0);
}

tree::TerminalNode* LatteParser::Expr1NullContext::ParBR() {
  return getToken(LatteParser::ParBR, 0);
}

tree::TerminalNode* LatteParser::Expr1NullContext::KNull() {
  return getToken(LatteParser::KNull, 0);
}


size_t LatteParser::Expr1NullContext::getRuleIndex() const {
  return LatteParser::RuleExpr1Null;
}

void LatteParser::Expr1NullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr1Null(this);
}

void LatteParser::Expr1NullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr1Null(this);
}

LatteParser::Expr1NullContext* LatteParser::expr1Null() {
  Expr1NullContext *_localctx = _tracker.createInstance<Expr1NullContext>(_ctx, getState());
  enterRule(_localctx, 62, LatteParser::RuleExpr1Null);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    match(LatteParser::ParBL);
    setState(346);
    match(LatteParser::Identifier);
    setState(347);
    match(LatteParser::ParBR);
    setState(348);
    match(LatteParser::KNull);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallListContext ------------------------------------------------------------------

LatteParser::CallListContext::CallListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LatteParser::ExprContext *> LatteParser::CallListContext::expr() {
  return getRuleContexts<LatteParser::ExprContext>();
}

LatteParser::ExprContext* LatteParser::CallListContext::expr(size_t i) {
  return getRuleContext<LatteParser::ExprContext>(i);
}


size_t LatteParser::CallListContext::getRuleIndex() const {
  return LatteParser::RuleCallList;
}

void LatteParser::CallListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallList(this);
}

void LatteParser::CallListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LatteListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallList(this);
}

LatteParser::CallListContext* LatteParser::callList() {
  CallListContext *_localctx = _tracker.createInstance<CallListContext>(_ctx, getState());
  enterRule(_localctx, 64, LatteParser::RuleCallList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    expr();
    setState(355);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LatteParser::T__3) {
      setState(351);
      match(LatteParser::T__3);
      setState(352);
      expr();
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool LatteParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return decTypeSempred(dynamic_cast<DecTypeContext *>(context), predicateIndex);
    case 17: return expr5Sempred(dynamic_cast<Expr5Context *>(context), predicateIndex);
    case 18: return expr4Sempred(dynamic_cast<Expr4Context *>(context), predicateIndex);
    case 19: return expr3Sempred(dynamic_cast<Expr3Context *>(context), predicateIndex);
    case 20: return expr2Sempred(dynamic_cast<Expr2Context *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LatteParser::decTypeSempred(DecTypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool LatteParser::expr5Sempred(Expr5Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool LatteParser::expr4Sempred(Expr4Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 3);
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool LatteParser::expr3Sempred(Expr3Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 4);
    case 10: return precpred(_ctx, 3);
    case 11: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool LatteParser::expr2Sempred(Expr2Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> LatteParser::_decisionToDFA;
atn::PredictionContextCache LatteParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LatteParser::_atn;
std::vector<uint16_t> LatteParser::_serializedATN;

std::vector<std::string> LatteParser::_ruleNames = {
  "main", "topDef", "type", "extendBlock", "typeMember", "typeVar", "function", 
  "funcArgs", "arg", "stmt", "block", "decVar", "decType", "typeName", "expr", 
  "expr7", "expr6", "expr5", "expr4", "expr3", "expr2", "expr1", "expr1IntConstant", 
  "expr1StringConstant", "expr1BoolConstant", "expr1Variable", "expr1Minus", 
  "expr1Not", "expr1Par", "expr1NewArray", "expr1NewObject", "expr1Null", 
  "callList"
};

std::vector<std::string> LatteParser::_literalNames = {
  "", "'{'", "'}'", "';'", "','", "'+'", "'-'", "'/'", "'*'", "'%'", "'++'", 
  "'--'", "'='", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'!'", "'&&'", 
  "'||'", "'['", "']'", "'('", "')'", "'.'", "'return'", "'while'", "'if'", 
  "'else'", "'class'", "'extends'", "'new'", "'int'", "'string'", "'void'", 
  "'boolean'", "'true'", "'false'", "'null'"
};

std::vector<std::string> LatteParser::_symbolicNames = {
  "", "", "", "", "", "OPlus", "OMinus", "ODiv", "OMul", "OMod", "OPlusPlus", 
  "OMinusMinus", "OAss", "OLT", "OLTE", "OGT", "OGTE", "OEq", "ONEq", "ONot", 
  "OAnd", "OOr", "OArrBL", "OArrBR", "ParBL", "ParBR", "Dot", "Kreturn", 
  "Kwhile", "Kif", "Kelse", "Kclass", "Kextends", "Knew", "Kint", "Kstring", 
  "Kvoid", "Kbool", "KTrue", "KFalse", "KNull", "Identifier", "IntLiteral", 
  "StringLiteral", "Whitespace", "BlockComment", "LineComment"
};

dfa::Vocabulary LatteParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LatteParser::_tokenNames;

LatteParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x30, 0x169, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x3, 0x2, 0x7, 0x2, 0x46, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x49, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4f, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x54, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x58, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x5b, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x64, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x75, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0x78, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7c, 0xa, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x87, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x8a, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb8, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x7, 0xc, 0xbc, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xbf, 0xb, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xc7, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0xcf, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xd2, 0xb, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0xdd, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xe4, 0xa, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0xfb, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xfe, 0xb, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x109, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x10c, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x7, 0x15, 0x11a, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x11d, 0xb, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x5, 0x16, 0x12d, 0xa, 0x16, 0x3, 0x16, 0x7, 0x16, 
    0x130, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x133, 0xb, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x13f, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x7, 0x22, 0x164, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x167, 0xb, 0x22, 0x3, 0x22, 0x2, 0x7, 0x1a, 0x24, 0x26, 0x28, 0x2a, 
    0x23, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x2, 0x4, 0x4, 
    0x2, 0x24, 0x27, 0x2b, 0x2b, 0x3, 0x2, 0x28, 0x29, 0x2, 0x178, 0x2, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x5e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe5, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xff, 0x3, 0x2, 0x2, 0x2, 0x28, 0x10d, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x140, 0x3, 0x2, 0x2, 0x2, 0x30, 0x142, 0x3, 0x2, 0x2, 0x2, 0x32, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x146, 0x3, 0x2, 0x2, 0x2, 0x36, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x152, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x158, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x46, 0x5, 0x4, 0x3, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x2, 0x2, 0x3, 0x4b, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x4f, 0x5, 0xe, 0x8, 0x2, 0x4d, 0x4f, 0x5, 0x6, 0x4, 
    0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x21, 0x2, 0x2, 0x51, 
    0x53, 0x7, 0x2b, 0x2, 0x2, 0x52, 0x54, 0x5, 0x8, 0x5, 0x2, 0x53, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x55, 0x59, 0x7, 0x3, 0x2, 0x2, 0x56, 0x58, 0x5, 0xa, 
    0x6, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5d, 0x7, 0x4, 0x2, 0x2, 0x5d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 
    0x7, 0x22, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x2b, 0x2, 0x2, 0x60, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x64, 0x5, 0xc, 0x7, 0x2, 0x62, 0x64, 0x5, 0xe, 
    0x8, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0xb, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x5, 0x1a, 0xe, 0x2, 
    0x66, 0x67, 0x7, 0x2b, 0x2, 0x2, 0x67, 0x68, 0x7, 0x5, 0x2, 0x2, 0x68, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x5, 0x1a, 0xe, 0x2, 0x6a, 0x6b, 
    0x7, 0x2b, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x10, 0x9, 0x2, 0x6c, 0x6d, 0x5, 
    0x16, 0xc, 0x2, 0x6d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x1a, 
    0x2, 0x2, 0x6f, 0x7c, 0x7, 0x1b, 0x2, 0x2, 0x70, 0x71, 0x7, 0x1a, 0x2, 
    0x2, 0x71, 0x76, 0x5, 0x12, 0xa, 0x2, 0x72, 0x73, 0x7, 0x6, 0x2, 0x2, 
    0x73, 0x75, 0x5, 0x12, 0xa, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x1b, 0x2, 0x2, 0x7a, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x11, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x1a, 0xe, 0x2, 
    0x7e, 0x7f, 0x7, 0x2b, 0x2, 0x2, 0x7f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0xb8, 0x7, 0x5, 0x2, 0x2, 0x81, 0xb8, 0x5, 0x16, 0xc, 0x2, 0x82, 0x83, 
    0x5, 0x1a, 0xe, 0x2, 0x83, 0x88, 0x5, 0x18, 0xd, 0x2, 0x84, 0x85, 0x7, 
    0x6, 0x2, 0x2, 0x85, 0x87, 0x5, 0x18, 0xd, 0x2, 0x86, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 
    0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x5, 0x2, 0x2, 0x8c, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x5, 0x1e, 0x10, 0x2, 0x8e, 0x8f, 
    0x7, 0xe, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x1e, 0x10, 0x2, 0x90, 0x91, 0x7, 
    0x5, 0x2, 0x2, 0x91, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x5, 0x1e, 
    0x10, 0x2, 0x93, 0x94, 0x7, 0xc, 0x2, 0x2, 0x94, 0x95, 0x7, 0x5, 0x2, 
    0x2, 0x95, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x5, 0x1e, 0x10, 0x2, 
    0x97, 0x98, 0x7, 0xd, 0x2, 0x2, 0x98, 0x99, 0x7, 0x5, 0x2, 0x2, 0x99, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x1d, 0x2, 0x2, 0x9b, 0x9c, 
    0x5, 0x1e, 0x10, 0x2, 0x9c, 0x9d, 0x7, 0x5, 0x2, 0x2, 0x9d, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x1d, 0x2, 0x2, 0x9f, 0xb8, 0x7, 0x5, 
    0x2, 0x2, 0xa0, 0xa1, 0x7, 0x1f, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x1a, 0x2, 
    0x2, 0xa2, 0xa3, 0x5, 0x1e, 0x10, 0x2, 0xa3, 0xa4, 0x7, 0x1b, 0x2, 0x2, 
    0xa4, 0xa5, 0x5, 0x14, 0xb, 0x2, 0xa5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0xa7, 0x7, 0x1f, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x1a, 0x2, 0x2, 0xa8, 0xa9, 
    0x5, 0x1e, 0x10, 0x2, 0xa9, 0xaa, 0x7, 0x1b, 0x2, 0x2, 0xaa, 0xab, 0x5, 
    0x14, 0xb, 0x2, 0xab, 0xac, 0x7, 0x20, 0x2, 0x2, 0xac, 0xad, 0x5, 0x14, 
    0xb, 0x2, 0xad, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x1e, 0x2, 
    0x2, 0xaf, 0xb0, 0x7, 0x1a, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0x1e, 0x10, 0x2, 
    0xb1, 0xb2, 0x7, 0x1b, 0x2, 0x2, 0xb2, 0xb3, 0x5, 0x14, 0xb, 0x2, 0xb3, 
    0xb8, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x1e, 0x10, 0x2, 0xb5, 0xb6, 
    0x7, 0x5, 0x2, 0x2, 0xb6, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x80, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0x81, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0x96, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbd, 0x7, 
    0x3, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x14, 0xb, 0x2, 0xbb, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x4, 0x2, 0x2, 0xc1, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc7, 0x7, 0x2b, 0x2, 0x2, 0xc3, 0xc4, 
    0x7, 0x2b, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0xe, 0x2, 0x2, 0xc5, 0xc7, 0x5, 
    0x1e, 0x10, 0x2, 0xc6, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0x19, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x8, 0xe, 0x1, 
    0x2, 0xc9, 0xca, 0x5, 0x1c, 0xf, 0x2, 0xca, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xcc, 0xc, 0x3, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x18, 0x2, 0x2, 0xcd, 
    0xcf, 0x7, 0x19, 0x2, 0x2, 0xce, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd4, 0x9, 0x2, 0x2, 0x2, 0xd4, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd6, 0x5, 0x20, 0x11, 0x2, 0xd6, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd8, 0x5, 0x22, 0x12, 0x2, 0xd8, 0xd9, 0x7, 0x17, 0x2, 0x2, 0xd9, 
    0xda, 0x5, 0x20, 0x11, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 
    0x5, 0x22, 0x12, 0x2, 0xdc, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xdd, 0x21, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x24, 
    0x13, 0x2, 0xdf, 0xe0, 0x7, 0x16, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x22, 0x12, 
    0x2, 0xe1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 0x5, 0x24, 0x13, 0x2, 
    0xe3, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x8, 0x13, 0x1, 0x2, 0xe6, 0xe7, 
    0x5, 0x26, 0x14, 0x2, 0xe7, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0xc, 
    0x9, 0x2, 0x2, 0xe9, 0xea, 0x7, 0xf, 0x2, 0x2, 0xea, 0xfb, 0x5, 0x26, 
    0x14, 0x2, 0xeb, 0xec, 0xc, 0x8, 0x2, 0x2, 0xec, 0xed, 0x7, 0x10, 0x2, 
    0x2, 0xed, 0xfb, 0x5, 0x26, 0x14, 0x2, 0xee, 0xef, 0xc, 0x7, 0x2, 0x2, 
    0xef, 0xf0, 0x7, 0x11, 0x2, 0x2, 0xf0, 0xfb, 0x5, 0x26, 0x14, 0x2, 0xf1, 
    0xf2, 0xc, 0x6, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x12, 0x2, 0x2, 0xf3, 0xfb, 
    0x5, 0x26, 0x14, 0x2, 0xf4, 0xf5, 0xc, 0x5, 0x2, 0x2, 0xf5, 0xf6, 0x7, 
    0x13, 0x2, 0x2, 0xf6, 0xfb, 0x5, 0x26, 0x14, 0x2, 0xf7, 0xf8, 0xc, 0x4, 
    0x2, 0x2, 0xf8, 0xf9, 0x7, 0x14, 0x2, 0x2, 0xf9, 0xfb, 0x5, 0x26, 0x14, 
    0x2, 0xfa, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xee, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfe, 
    0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0x25, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0x100, 0x8, 0x14, 0x1, 0x2, 0x100, 0x101, 0x5, 0x28, 
    0x15, 0x2, 0x101, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0xc, 0x5, 
    0x2, 0x2, 0x103, 0x104, 0x7, 0x7, 0x2, 0x2, 0x104, 0x109, 0x5, 0x28, 
    0x15, 0x2, 0x105, 0x106, 0xc, 0x4, 0x2, 0x2, 0x106, 0x107, 0x7, 0x8, 
    0x2, 0x2, 0x107, 0x109, 0x5, 0x28, 0x15, 0x2, 0x108, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x105, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x27, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 
    0x2, 0x10d, 0x10e, 0x8, 0x15, 0x1, 0x2, 0x10e, 0x10f, 0x5, 0x2a, 0x16, 
    0x2, 0x10f, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0xc, 0x6, 0x2, 
    0x2, 0x111, 0x112, 0x7, 0xa, 0x2, 0x2, 0x112, 0x11a, 0x5, 0x2a, 0x16, 
    0x2, 0x113, 0x114, 0xc, 0x5, 0x2, 0x2, 0x114, 0x115, 0x7, 0xb, 0x2, 
    0x2, 0x115, 0x11a, 0x5, 0x2a, 0x16, 0x2, 0x116, 0x117, 0xc, 0x4, 0x2, 
    0x2, 0x117, 0x118, 0x7, 0x9, 0x2, 0x2, 0x118, 0x11a, 0x5, 0x2a, 0x16, 
    0x2, 0x119, 0x110, 0x3, 0x2, 0x2, 0x2, 0x119, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x116, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 
    0x11e, 0x11f, 0x8, 0x16, 0x1, 0x2, 0x11f, 0x120, 0x5, 0x2c, 0x17, 0x2, 
    0x120, 0x131, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0xc, 0x6, 0x2, 0x2, 
    0x122, 0x123, 0x7, 0x1c, 0x2, 0x2, 0x123, 0x130, 0x7, 0x2b, 0x2, 0x2, 
    0x124, 0x125, 0xc, 0x5, 0x2, 0x2, 0x125, 0x126, 0x7, 0x18, 0x2, 0x2, 
    0x126, 0x127, 0x5, 0x1e, 0x10, 0x2, 0x127, 0x128, 0x7, 0x19, 0x2, 0x2, 
    0x128, 0x130, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0xc, 0x4, 0x2, 0x2, 
    0x12a, 0x12c, 0x7, 0x1a, 0x2, 0x2, 0x12b, 0x12d, 0x5, 0x42, 0x22, 0x2, 
    0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x7, 0x1b, 0x2, 0x2, 
    0x12f, 0x121, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x12f, 0x129, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 
    0x132, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 
    0x13f, 0x5, 0x2e, 0x18, 0x2, 0x135, 0x13f, 0x5, 0x30, 0x19, 0x2, 0x136, 
    0x13f, 0x5, 0x34, 0x1b, 0x2, 0x137, 0x13f, 0x5, 0x32, 0x1a, 0x2, 0x138, 
    0x13f, 0x5, 0x36, 0x1c, 0x2, 0x139, 0x13f, 0x5, 0x38, 0x1d, 0x2, 0x13a, 
    0x13f, 0x5, 0x3a, 0x1e, 0x2, 0x13b, 0x13f, 0x5, 0x3c, 0x1f, 0x2, 0x13c, 
    0x13f, 0x5, 0x3e, 0x20, 0x2, 0x13d, 0x13f, 0x5, 0x40, 0x21, 0x2, 0x13e, 
    0x134, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x135, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 
    0x13c, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x7, 0x2c, 0x2, 0x2, 0x141, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x7, 0x2d, 0x2, 0x2, 0x143, 
    0x31, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x9, 0x3, 0x2, 0x2, 0x145, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0x2b, 0x2, 0x2, 0x147, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x7, 0x8, 0x2, 0x2, 0x149, 0x14a, 
    0x5, 0x2c, 0x17, 0x2, 0x14a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 
    0x7, 0x15, 0x2, 0x2, 0x14c, 0x14d, 0x5, 0x2c, 0x17, 0x2, 0x14d, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x7, 0x1a, 0x2, 0x2, 0x14f, 0x150, 
    0x5, 0x1e, 0x10, 0x2, 0x150, 0x151, 0x7, 0x1b, 0x2, 0x2, 0x151, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x7, 0x23, 0x2, 0x2, 0x153, 0x154, 
    0x5, 0x1a, 0xe, 0x2, 0x154, 0x155, 0x7, 0x18, 0x2, 0x2, 0x155, 0x156, 
    0x5, 0x1e, 0x10, 0x2, 0x156, 0x157, 0x7, 0x19, 0x2, 0x2, 0x157, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x7, 0x23, 0x2, 0x2, 0x159, 0x15a, 
    0x7, 0x2b, 0x2, 0x2, 0x15a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 
    0x7, 0x1a, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x2b, 0x2, 0x2, 0x15d, 0x15e, 
    0x7, 0x1b, 0x2, 0x2, 0x15e, 0x15f, 0x7, 0x2a, 0x2, 0x2, 0x15f, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x160, 0x165, 0x5, 0x1e, 0x10, 0x2, 0x161, 0x162, 
    0x7, 0x6, 0x2, 0x2, 0x162, 0x164, 0x5, 0x1e, 0x10, 0x2, 0x163, 0x161, 
    0x3, 0x2, 0x2, 0x2, 0x164, 0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x47, 0x4e, 0x53, 
    0x59, 0x63, 0x76, 0x7b, 0x88, 0xb7, 0xbd, 0xc6, 0xd0, 0xdc, 0xe3, 0xfa, 
    0xfc, 0x108, 0x10a, 0x119, 0x11b, 0x12c, 0x12f, 0x131, 0x13e, 0x165, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LatteParser::Initializer LatteParser::_init;
