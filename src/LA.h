
// Generated from src/LA.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  LA : public antlr4::Lexer {
public:
  enum {
    PalvraChave = 1, OP_LOGICO = 2, NUM_INT = 3, NUM_REAL = 4, IDENT = 5, 
    CADEIA = 6, COMENTARIO = 7, ESPACO = 8, LINHA = 9, DELIMITADOR = 10, 
    ABRE_PAR = 11, FECHA_PAR = 12, ABRE_COL = 13, FECHA_COL = 14, OP_ARIT = 15, 
    OP_REL = 16, ATE = 17, VIRGULA = 18, PONTO = 19, ERRO = 20
  };

  explicit LA(antlr4::CharStream *input);
  ~LA();

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

