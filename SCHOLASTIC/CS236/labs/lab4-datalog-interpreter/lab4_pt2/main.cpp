#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "TestCase.h"
#include "Interpreter.h"
#include "Lexer.h"
#include "Parser.h"

using namespace std;


void TestProgram(string fileName) {
    TestCase tc("Verify data is there and output the data: \n");
    bool gotProgram = false;
    Lexer l(fileName);
    Parser p(l.GetTokenVec());
    Interpreter i(p.GetDatalogProgram());

    int schemeSize = i.sVec.size();
    int factSize = i.fVec.size();

    if(schemeSize == 0 && factSize == 0)
        gotProgram = false;
    else
        gotProgram = true;


    // tc.AssertEquals(true, gotProgram, "Tests that the schemes and facts vectors are not empty");
    // tc.AssertEquals("snap", i.GetName(0), "Compare expected name with returned name");
    // tc.AssertEquals("HasSameAddress", i.GetName(1), "Compare expected name with returned name");
    // tc.AssertEquals("NONE", i.GetName(4), "Compare expected name with returned name");
    // tc.AssertEquals(2, i.MakeRelation().size(), "There should be 2 relations stored");

    if(gotProgram) {
        cout << "\nSCHEMES DATA: " << endl;
        cout << i.datProg.MakeSchemesStr();
        cout << endl << "\nFACTS DATA: " << endl;
        cout << i.datProg.MakeFactsStr() << endl;
        cout << "\nQUERY DATA: " << endl;
        cout << i.datProg.MakeQueriesStr() << endl << endl;
    }    

    i.AllQueryEval();
}

int main(int argc, char** argv) {
    
    // TestProgram(argv[1]);

    // TestCase::PrintSummary();

    Lexer l(argv[1]);
    Parser p(l.GetTokenVec());
    Interpreter i(p.GetDatalogProgram());

    return 0;
}