#include "Row.h"

using namespace std;

Row::Row() {}

Row::~Row() {}

string Row::ToString() {
    stringstream ss;
    for(size_t i = 0; i < this->size(); i++) {
        ss << this->at(i) << " ";
    }
    ss << endl;
    return ss.str();
}