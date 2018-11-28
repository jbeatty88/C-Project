#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Header.h"
#include "DatalogProgram.h"
#include "Relation.h"
#include "Row.h"
#include "Database.h"


class Interpreter {
    public:
        DatalogProgram datProg;
        std::vector<Predicate> sVec;
        std::vector<Predicate> fVec;
        std::vector<Predicate> qVec;
        std::vector<Rule> rVec;
        Header newHead = Header();
        std::vector<size_t> projCol;
        std::vector<std::string> newVars;
        std::vector<std::string> oldVars;
        std::vector<std::string> qVals;
        Database db;

        std::string GetName(size_t n);
        std::vector<Relation> MakeRelation();
        std::vector<Relation> MakeRow(std::vector<Relation> r);
        void MakeDatabase(std::vector<Relation> r);

        Relation SingleQueryEval(std::string name, size_t idx);
        void AddToDB(Relation& r);
        void ConstSelect(Relation& r, size_t idx);
        void VarSelect(Relation& r, size_t idx);
        void Proj(Relation& r);
        std::string Format(Relation& r, size_t idx);
        void ProjQueue(std::string vn, size_t col);
        void AllQueryEval();
        // void NewVarCheck(std::string v, size_t col);

        void EvaluateRules();
        std::vector<Relation> RightHandEval(size_t x);
        void Join(Relation& r, std::vector<Relation>& rightHandRels);

        Interpreter();
        Interpreter(DatalogProgram dp);
        ~Interpreter();

        friend std::ostream &operator<<(std::ostream &, const Interpreter &);
};