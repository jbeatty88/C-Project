#pragma once

#include <string>
#include <sstream>
#include <vector>

class Row: public std::vector<std::string> {
    public: 
    public:
        Row();
        ~Row();

        std::string ToString();
};