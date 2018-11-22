#include "Header.h"

using namespace std;

Header::Header() {}

Header::~Header() {}

vector<string> Header::GetAttr() {
    vector<string> attrVec;
    for(size_t i = 0; i < this->size(); i++) {
        attrVec.push_back(this->at(i));
    }
    return attrVec;
}

string Header::ToString() {
    stringstream ss;
    for(size_t i = 0; i < this->size(); i++) {
        ss << this->at(i) << " ";
    }
    return ss.str();
}