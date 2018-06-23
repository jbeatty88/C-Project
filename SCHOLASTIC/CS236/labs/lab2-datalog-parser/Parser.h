#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "DatalogProgram.h"
#include "Token.h"
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"

class Parser 
{
private:
    vector<Token> tokens;
    vector<Predicate> predicates;
    vector<Rule> rules;
    vector<string> domain;

    Rule myRule; //FIXME
    Predicate myPredicate; //FIXME
    Parameter myParameter; //FIXME

    DatalogProgram dataLogger; //FIXME

    int idx;
    Token currToken;
    string strError;

public:
    Parser(vector<Token> tokenList);

    void SyntaxCheck(std::string checkedString);
    void Parse();
    void Scheme();
    void SchemeList();
    void Predicate();
    void PredicateList();
    void Parameter();
    void ParameterList();
    void Fact();
    void FactList();
    void Rule();
    void RuleList();
    void Query();
    void QueryList();

    void print();
    void print(char * fileName);
    DatalogProgram getProgram();
};