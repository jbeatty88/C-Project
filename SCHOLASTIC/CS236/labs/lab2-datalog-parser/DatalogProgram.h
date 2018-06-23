#pragma once

#include <string>
#include <vector>
#include "Rule.h"
#include "Predicate.h"

/* datalogProgram	->	SCHEMES COLON scheme schemeList   FACTS COLON factList   RULES COLON ruleList   QUERIES COLON query queryList */

class DatalogProgram
{
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;

public:
    DatalogProgram(){};

    //FIXME
    void InsertFact(vector<Predicate> factInsert);//FIXME
    void InsertScheme(vector<Predicate> schemeInsert);//FIXME
    void InsertQuery(vector<Predicate> queryInsert);//FIXME
    void InsertRule(vector<Rule> ruleInsert);//FIXME


    vector<Predicate> GetSchemes() const {return schemes;}
    vector<Predicate> GetFacts() const {return facts;}
    vector<Predicate> GetQueries() const {return queries;}
    vector<Rule> GetRules() const {return rules;}

    std::string toString();
};
