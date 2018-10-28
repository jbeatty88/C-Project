#include "Interpreter.h"

using namespace std;

Interpreter::Interpreter() {
    cout << "\033[1;34mINTERPRETER CLASS cstr\033[0m\n" << endl;
}

Interpreter::Interpreter(DatalogProgram program) {
    cout << "\033[1;36mINTERPRETER CLASS cstr\033[0m\n" << endl;
    this->programData = program;
    this->schemes = program.schemesPredVec;
    this->facts = program.factsPredVec;
    this->schemeStr = program.MakeSchemesStr();
    this->factStr = program.MakeFactsStr();
    this->name = GetName(); 
    GetHeader(schemes);
    // this->header = GetHeader(); 
}

Interpreter::~Interpreter() {
    cout << "\033[1;33m\nINTERPRETER CLASS Dcstr\033[0m\n" << endl;
}

Interpreter::Interpreter(const Interpreter &other) {
    cout << "INTERPRETER CLASS COPY cstr" << endl;
}

// Interpreter &Interpreter::operator=(const Interpreter &other) {
//     cout << "Assignemnt in INTERPRETER CLASS" << endl;

//     return *this;
// }

string Interpreter::GetSchemesStr() { return this->schemeStr; }

string Interpreter::GetFactsStr() { return this->factStr; }

Header Interpreter::GetHeader(vector<Predicate> v) {
    // set<string> s;
    Header myHead = Header();
    size_t size = v.size();
    vector<Parameter> p;
    if(size != 0) {
        for(size_t i = 0; i < size; i++) {
            p = v[i].GetParams();
            for(size_t j = 0; j < p.size(); j++) {
                myHead.push_back(p[j].GetValue());
                // s.insert(p[j].GetValue());
            }
        }
    }

    // myHead.push_back
    return myHead;
}
// set<string> Interpreter::GetHeader() { 
//     set<string> s;
//     s.insert("A");
//     vector<Parameter> p = this->schemes[0].GetParams();
//     for(size_t i = 0; i < p.size(); i++) {
//         this->header.insert(p[i].GetValue());
//     }
//     return this->header;
//     return s;
// }

std::string Interpreter::GetName() { 
    return this->programData.schemesPredVec[0].GetId();    
}

ostream &operator<<(ostream &os, const Interpreter &i) {
    size_t schemesVecSize = i.programData.schemesPredVec.size();
    size_t factsVecSize = i.programData.factsPredVec.size();

    os << "Data Gathered from Datalog Program:" << endl;
    os << "\nSchemes Vec Size: ";
    os << schemesVecSize << endl;
    os << i.schemeStr;
    os << "\n\nFacts Vec Size: ";
    os << factsVecSize << endl;
    os << i.factStr;

    // os << "\n\n NAME: " << i.name << endl;

    return os;
}
