#pragma once

#include <string>
#include <iostream>
#include <set>

#include "Header.h"
#include "Row.h"

class Relation {
    public:
        std::string name;
        std::set<std::string> scheme;
        std::set<Row> rows;
        Header header = Header();

    public:
        Relation();
        Relation(std::string n, std::set<std::string> header);
        Relation(std::string n, Header h);
        ~Relation();

        void AddRow(Row r);

        std::string ToString();
        void PrintRows();
        void PrintHeader();
        void PrintName();

        Relation Select(std::string val, size_t col);
        Relation Select(size_t col1, size_t col2);
        Relation Project(std::vector<size_t> cols);
        Relation Rename(std::string name, Header head);


};