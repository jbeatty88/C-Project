#pragma once

#include <string>
#include <iostream>
#include <set>

#include "Header.h"
#include "Row.h"

class Relation {
    public:
        std::string name;
        // std::set<std::string> schema;
        Header header = Header();
        std::set<Row> rows;
        
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
        
        size_t GetRowCount();
        void SetRelName(std::string n);
        void SetHeader(Header h);
        void SetRows(std::set<Row> r);
        

        bool IsEmpty();
        bool IsJoinable(Row& rowA, Row& rowB, Header& headA, Header& headB);
        bool IsDuplicateRow(Row r);
        bool IsDiffAttr(Header h, std::string attr);
        

        Relation Select(std::string val, size_t col);
        Relation Select(size_t col1, size_t col2);
        Relation Project(std::vector<size_t> cols);
        Relation Rename(Header head);
        Relation Join(Relation& relA, Relation& relB);

        void Unionize(Relation& r);
        std::string RowStringer(Row& row);
        Header CombineSchemes(Header& hA, Header& hB);
        Row CombineTuples(Row& rowA, Row& rowB, Header& headA, Header& headB);
        


};