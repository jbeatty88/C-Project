#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {}

DatalogProgram::~DatalogProgram() {}

std::string DatalogProgram::ToString() {
    // Put together each formatted part
    std::stringstream ss;
    ss << "Success!\n";
    ss << MakeSchemesStr() << "\n" << MakeFactsStr() << "\n";
    ss << MakeRulesStr() << "\n" << MakeQueriesStr() << "\n";
    ss << MakeDomainStr() << "\n";
    return ss.str();
}

void DatalogProgram::PushScheme(Predicate scheme) { schemesPredVec.push_back(scheme); }

void DatalogProgram::PushFact(Predicate fact) { 
    factsPredVec.push_back(fact);
    InsertDomain(fact.GetParams());
}

void DatalogProgram::PushQuery(Predicate query) { queriesPredVec.push_back(query); }

void DatalogProgram::PushRule(Rule rule) { 
    rulesPredVec.push_back(rule); 
    InsertDomain(rule.GetPredicate().GetParams());
}

void DatalogProgram::InsertDomain(std::vector<Parameter> paramVec) {
    for(size_t i = 0; i < paramVec.size(); i++) {
        if(paramVec[i].GetType() == "STRING")
            domain.insert(paramVec[i].GetValue());
    }
}

std::string DatalogProgram::MakeSchemesStr() {
    // Format the Schemes section
    std::stringstream ss;
    ss << "Schemes(" << schemesPredVec.size() << "):";
    for(size_t i = 0; i < schemesPredVec.size(); i++)
        ss << "\n  " << schemesPredVec[i].ToString();
    return ss.str();
}

std::string DatalogProgram::MakeFactsStr() {
    // format 
    std::stringstream ss;
    ss << "Facts(" << factsPredVec.size() << "):";
    for(size_t i = 0; i < factsPredVec.size(); i++)
        ss << "\n  " << factsPredVec[i].ToString() << ".";
    return ss.str();
}

std::string DatalogProgram::MakeRulesStr() {
    std::stringstream ss;
    ss << "Rules(" << rulesPredVec.size() << "):";
    for(size_t i = 0; i < rulesPredVec.size(); i++)
        ss << "\n  " << rulesPredVec[i].ToString();
    return ss.str();
}

std::string DatalogProgram::MakeQueriesStr() {
    std::stringstream ss;
    ss << "Queries(" << queriesPredVec.size() << "):";
    for(size_t i = 0; i < queriesPredVec.size(); i++)
        ss << "\n  " << queriesPredVec[i].ToString() << "?";
    return ss.str();
}

std::string DatalogProgram::MakeDomainStr() {
    // Sets are already sorted
    std::stringstream ss;
    ss << "Domain(" << domain.size() << "):";
    std::set<std::string>::iterator itr;
    for(itr = domain.begin(); itr != domain.end(); itr++)
    ss << "\n  " << *itr;
    return ss.str();
}