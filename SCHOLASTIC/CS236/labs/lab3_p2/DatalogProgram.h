#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"
#include "Token.h"
#include "Expression.h"

class DatalogProgram {
    public:
        //We need FOUR vectors here
        // Vector of Predicates for Schemes
        std::vector<Predicate> schemesPredVec;
        // Vector of Predicates for Facts
        std::vector<Predicate> factsPredVec;
        // Vector of Predicates for Queries
        std::vector<Predicate> queriesPredVec;
        // Vector of Rules for the Rules
        std::vector<Rule> rulesPredVec;
        // Set of the Domain
        std::set<std::string> domain;

    public:
        DatalogProgram();
        ~DatalogProgram();
        std::string ToString();
        void PushScheme(Predicate scheme);
        void PushFact(Predicate fact);
        void PushQuery(Predicate query);
        void PushRule(Rule rule);
        void InsertDomain(std::vector<Parameter> paramVec);
        std::string MakeSchemesStr();
        std::string MakeFactsStr();
        std::string MakeRulesStr();
        std::string MakeQueriesStr();
        std::string MakeDomainStr();
};