#pragma once

#include <string>
#include <sstream>
#include <vector>

class Row: public std::vector<std::string> {
    private: 
    public:
        Row();
        ~Row();

        std::string ToString();
};