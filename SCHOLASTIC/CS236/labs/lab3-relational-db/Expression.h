#pragma once

#include <string>
#include <sstream>
#include "Parameter.h"

class Expression: public Parameter{

    private:
        Parameter* leftParam;
        Parameter* rightParam;
        std::string op;
    public:
        Expression();
        Expression(Parameter* lParam, std::string oper, Parameter* rParam);
        Expression(std::string lp, std::string op, std::string rp);
        ~Expression();
        std::string ToString();
        std::string GetType();
};