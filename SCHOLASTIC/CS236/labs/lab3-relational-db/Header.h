#pragma once

#include <vector>
#include <set>
#include <string>
#include <iostream>

class Header: public std::vector<std::string> {
    private:
    public:
        // std::set<std::string> header;

        Header();
        ~Header();
        Header(const Header &);
        Header &operator = (const Header &);

        friend std::ostream &operator<<(std::ostream &, const Header &);
};