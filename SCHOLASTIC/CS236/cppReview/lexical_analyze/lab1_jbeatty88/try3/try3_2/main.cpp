
#include <iostream>
#include <sstream>
#include "Lexer.h"
using namespace std;

int main(int argc, char** argv) {
    stringstream ss;

    if(argc != 2) {
      cout << "Please provide a file to scan" << endl;
      exit(1);
    }
    else {
      ss << argv[1];
      if (ss.str().length() > 3)
        Lexer lex(argv[1]);
    }
    return 0;
}
