
// Generated from Latte.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  LatteLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, OPlus = 5, OMinus = 6, ODiv = 7, 
    OMul = 8, OMod = 9, OPlusPlus = 10, OMinusMinus = 11, OAss = 12, OLT = 13, 
    OLTE = 14, OGT = 15, OGTE = 16, OEq = 17, ONEq = 18, ONot = 19, OAnd = 20, 
    OOr = 21, OArrBL = 22, OArrBR = 23, ParBL = 24, ParBR = 25, Dot = 26, 
    Kreturn = 27, Kwhile = 28, Kif = 29, Kelse = 30, Kclass = 31, Kextends = 32, 
    Knew = 33, Kint = 34, Kstring = 35, Kvoid = 36, Kbool = 37, KTrue = 38, 
    KFalse = 39, KNull = 40, Identifier = 41, IntLiteral = 42, StringLiteral = 43, 
    Whitespace = 44, BlockComment = 45, LineComment = 46
  };

  LatteLexer(antlr4::CharStream *input);
  ~LatteLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

