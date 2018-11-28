#include "Predicate.h"

Predicate::Predicate(): id("") {}

Predicate::Predicate(std::string id): id(id) {}

Predicate::Predicate(std::string id, std::vector<Parameter> pv): id(id), paramVec(pv) {}

Predicate::~Predicate() {}

std::string Predicate::ToString() {
    std::stringstream ss;
    ss << id << "(";
    for(size_t i = 0; i < paramVec.size(); i++) {
        if(i == 0)
            ss << paramVec[i].ToString();
        else
            ss << "," << paramVec[i].ToString();
    }
    ss << ")";
    return ss.str();
}

std::string Predicate::GetId() { return id; }

std::vector<Parameter> Predicate::GetParams() { return paramVec; }

void Predicate::PushParam(Parameter p) { paramVec.push_back(p); }






