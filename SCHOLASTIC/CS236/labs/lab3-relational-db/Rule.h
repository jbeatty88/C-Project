#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Predicate.h"

class Rule {
    private:
        Predicate pred;
        std::vector<Predicate> predVec;
    public:
        Rule();
        Rule(Predicate p);
        Rule(Predicate p, std::vector<Predicate> pv);
        ~Rule();
        std::string ToString();
        void PushPred(Predicate p);
        std::vector<Predicate> GetPredVec();
        Predicate GetPredicate();
};