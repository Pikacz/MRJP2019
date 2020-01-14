
// Generated from Latte.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  LatteLexer : public antlr4::Lexer {
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

