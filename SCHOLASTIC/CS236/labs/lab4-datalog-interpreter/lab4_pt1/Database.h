#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Relation.h"

class Database : public std::map<std::string, Relation> {
    public: 
        Database();
        ~Database();

};