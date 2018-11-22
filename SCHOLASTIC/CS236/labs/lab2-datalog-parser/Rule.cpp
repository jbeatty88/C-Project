#include "Rule.h"

Rule::Rule() {}

Rule::Rule(Predicate p): pred(p) {}

Rule::Rule(Predicate p, std::vector<Predicate> pv): pred(p), predVec(pv) {}

Rule::~Rule() {}

std::string Rule::ToString() {
    std::stringstream ss;
    ss << pred.ToString() << " :- ";
    for(size_t i = 0; i < predVec.size(); i++){
        if(i == 0)
            ss << predVec[i].ToString();
        else
            ss << "," << predVec[i].ToString();
    }
    ss << ".";
    return ss.str();
}

void Rule::PushPred(Predicate p) { predVec.push_back(p); }

std::vector<Predicate> Rule::GetPredVec() { return predVec; }

Predicate Rule::GetPredicate() {
    std::stringstream ss;
    ss << pred.ToString() << " :- ";
    for(size_t i = 0; i < predVec.size(); i++) {
        if(i == 0) 
            ss << predVec[i].ToString();
        else
            ss << "," << predVec[i].ToString();
    }
    ss << ".";
    return ss.str();
}