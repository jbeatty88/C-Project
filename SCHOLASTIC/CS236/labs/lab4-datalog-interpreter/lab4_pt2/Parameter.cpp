#include "Parameter.h"

Parameter::Parameter(): type(""), value("") {}

Parameter::Parameter(std::string t, std::string v, bool tf): type(t), value(v), isConstant(tf) {}

Parameter::~Parameter() {}

std::string Parameter::ToString() { return GetValue(); }

std::string Parameter::GetType() { return type; }

std::string Parameter::GetValue() { return value; }
