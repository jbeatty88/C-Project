#pragma once

#include <map>
#include <iostream>
#include <string>
// #include "Relation.h"

class Database : public std::map<std::string, Relation> {
    private:
    public:
        Database();
        ~Database();
        Database(const Database &);
        Database &operator = (const Database &);

};