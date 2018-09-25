#include <iostream>
#include "InputStream.h"
#include "Lexer.h"
//#include "Token.h"


using namespace std;


int main(int argc, char** argv) {
  InputStream inStream(argv[1]);

  Lexer Lex;

  Lex.PrintVec(inStream.MakeInputVec());
  Lex.MapVec(inStream.GetVecSize(),inStream.MakeInputVec());

  




  return 0;
};
