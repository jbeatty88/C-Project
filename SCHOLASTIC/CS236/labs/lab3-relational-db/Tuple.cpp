#include "Tuple.h"

using std::cout; using std::string; using std::endl; using std::stringstream;
using std::ostream;
Tuple::Tuple() {
    cout << "Constructor in TUPLE CLASS" << endl;
}

Tuple::~Tuple() {
    cout << "Deconstructor in TUPLE CLASS" << endl;
}

Tuple::Tuple(const Tuple &other) {
    cout << "Copy Cstr in TUPLE CLASS" << endl;
}

Tuple &Tuple::operator=(const Tuple &other) {
    cout << "Assignemnt in TUPLE CLASS" << endl;

    return *this;
}

string Tuple::ToString() {
    stringstream ss;
    for(size_t i = 0; i < this->size(); i++) {
        ss << this->at(i) << endl;
    }
    return ss.str();
}

ostream &operator<<(ostream &os, const Tuple &t) {
    os << "TUPLE CLASS operator overload" << endl;
    return os;
}