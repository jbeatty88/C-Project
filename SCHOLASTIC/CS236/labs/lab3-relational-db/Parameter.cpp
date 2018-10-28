#include "Parameter.h"

Parameter::Parameter(): type(""), value("") {}

Parameter::Parameter(std::string t, std::string v): type(t), value(v) {}

Parameter::~Parameter() {}

std::string Parameter::ToString() { return GetValue(); }

std::string Parameter::GetType() { return type; }

std::string Parameter::GetValue() { return value; }
