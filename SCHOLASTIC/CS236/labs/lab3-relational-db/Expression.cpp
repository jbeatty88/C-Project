#include "Expression.h"

Expression::Expression() {
    this->leftParam = NULL;
    this->rightParam = NULL;
    this->op = "";
};

Expression::Expression(Parameter* lParam, std::string oper, Parameter* rParam) {
    this->leftParam = lParam;
    this->op = oper;
    this->rightParam = rParam;
}

Expression::Expression(std::string lp, std::string op, std::string rp) {}

Expression::~Expression() {};

std::string Expression::ToString() {
    std::stringstream ss;
    ss << "(" << leftParam->GetValue() << op << rightParam->GetValue() << ")";
    return ss.str();
}

std::string Expression::GetType() { return "EXPRESSION"; }