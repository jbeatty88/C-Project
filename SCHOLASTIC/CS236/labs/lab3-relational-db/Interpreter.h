#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Header.h"
// #include "Database.h"

class Interpreter {
    public:
        DatalogProgram programData;
        // Database db;
        std::vector<Predicate> schemes;
        std::vector<Predicate> facts;
        std::string schemeStr;
        std::string factStr;
        std::string name;
        
        // std::set<std::string> headSet;

        Interpreter();
        Interpreter(DatalogProgram program);
        ~Interpreter();
        Interpreter(const Interpreter &);
        // Interpreter &operator = (const Interpreter &);


        std::string GetSchemesStr();
        std::string GetFactsStr();
        Header GetHeader(std::vector<Predicate> v);
        // std::set<std::string> GetHeader();
        std::string GetName();

        // How to make it do the other classes in this class
        // do not need to know any of the classes in the DL


        // void MakeSchemeRelation();
        // void MakeDatabase(); 

        // void MakeFactTuples();

        // void GetHeader();
        // void GetName();



        friend std::ostream &operator<<(std::ostream &, const Interpreter &);

};