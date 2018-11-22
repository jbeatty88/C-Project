#pragma once
#include <string>
#include <sstream>
#include "Token.h"

class Parameter {
    public: 
        Parameter();
        Parameter(std::string t, std::string v);
        ~Parameter();
        std::string ToString();
        std::string GetType();
        std::string GetValue();
        std::string type;
        std::string value;

};