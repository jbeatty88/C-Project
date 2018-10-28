#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Parameter.h"
#include "Expression.h"

class Predicate {
    public:
        std::string id;
        std::vector<Parameter> paramVec;
        Predicate();
        Predicate(std::string id);
        Predicate(std::string id, std::vector<Parameter> pv);
        Predicate(std::string id, std::string exprString);
        ~Predicate();
        std::string ToString();
        std::string GetId();
        std::vector<Parameter> GetParams();
        void PushParam(Parameter p);
};