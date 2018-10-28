#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
class Tuple : public std::vector<std::string> {
    private:
    public:
        Tuple(); // Constructor
        ~Tuple(); // Destructor
        Tuple(const Tuple &); //Copy Constructor
        Tuple &operator = (const Tuple &); //Assignment Operator

        std::string ToString();

        friend std::ostream &operator<<(std::ostream &, const Tuple &);
};