#pragma once
#include <string>
#include "Header.h"
#include "Tuple.h"

class Relation {
    private:
        std::string name;
        Header header;

    public:
        Relation();
        Relation(std::string n, Header h);
        ~Relation();
        Relation(const Relation &);
        Relation &operator = (const Relation &);
        void AddTuple(Tuple t);

        friend std::ostream &operator<<(std::ostream &, const Relation &);
};
