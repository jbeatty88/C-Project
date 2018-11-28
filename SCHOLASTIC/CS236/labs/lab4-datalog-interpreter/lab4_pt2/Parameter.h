#pragma once
#include <string>
#include <sstream>
#include "Token.h"

class Parameter {
    public:
        std::string type;
        std::string value;
        bool isConstant;

    public: 
        Parameter();
        Parameter(std::string t, std::string v, bool tf);
        ~Parameter();
        std::string ToString();
        std::string GetType();
        std::string GetValue();
};