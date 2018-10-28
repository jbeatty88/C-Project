#include <iostream>

#include "Interpreter.h"
#include "Parser.h"
#include "Lexer.h"
#include "DatalogProgram.h"



using namespace std;

int main(int argc, char** argv) {
    Lexer l(argv[1]);
    Parser p(l.GetTokenVec());
    DatalogProgram dp = p.GetDatalogProgram();
    Interpreter i(dp);

    cout << i << endl;

    return 0;
}