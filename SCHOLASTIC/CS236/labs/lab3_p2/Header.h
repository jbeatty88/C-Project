#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Header: public std::vector<std::string> {       
    public:
        Header();
        ~Header();

        std::vector<std::string> GetAttr();
        std::string ToString();
};