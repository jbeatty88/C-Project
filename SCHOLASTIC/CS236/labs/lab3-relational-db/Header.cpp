#include "Header.h"

using namespace std;

Header::Header() {
    cout << "Constructor in Header CLASS" << endl;
    
}

Header::~Header() {
    cout << "Deconstructor in Header CLASS" << endl;
}

Header::Header(const Header &other) {
    cout << "Copy Cstr in Header CLASS" << endl;
}

// Header &Header::operator=(const Header &other) {
//     cout << "Assignemnt in Header CLASS" << endl;

//     return *this;
// }

ostream &operator<<(ostream &os, const Header &t) {
    os << "Header CLASS operator overload" << endl;
    return os;
}