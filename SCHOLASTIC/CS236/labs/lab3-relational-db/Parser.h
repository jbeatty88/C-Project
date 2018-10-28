#pragma once

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"

class Parser {
private:
    std::vector<Token> tokens;
    size_t idx;
    Token currentToken;
    std::string strError;

    //temporary variables 
    DatalogProgram tmpDLog;
    Predicate tmpPred;
    Rule tmpRule;


public:
    Parser(std::vector<Token> tokVec);
    ~Parser();
    bool IsMatch(TokenType type);
    Token GetToken(size_t i = 0);
    void ParseDataLogProgram();
    void ParseScheme();
    void ParseSchemeList();
    void ParseIDList();
    void ParseFact();
    void ParseFactList();
    void ParseRule();
    void ParseRuleList();
    void ParseHeadPredicate();
    void ParsePredicate();
    void ParsePredicateList();
    void ParseParameter();
    void ParseParameterList();
    void ParseExpression();
    std::string ParseExpressionParameter();
    std::string ParseOperator();
    void ParseQuery();
    void ParseQueryList();
    void ParseStringList();
    DatalogProgram GetDatalogProgram();
};