#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Parameter.h"

class Predicate {
    public:
        std::string id;
        std::vector<Parameter> paramVec;
    public:
        Predicate();
        Predicate(std::string id);
        Predicate(std::string id, std::vector<Parameter> pv);
        ~Predicate();
        std::string ToString();
        std::string GetId();
        std::vector<Parameter> GetParams();
        void PushParam(Parameter p);
};