/*
  Joshua Beatty
  2018
*/

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "Lexer.h"
#include "Parser.h"


using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cout << "Please enter file name!";
		return -1;
	}
	Lexer lexer(argv[1]);
	//lexer.PrintVec();
	Parser p(lexer.GetTokenVec()); 

	return 0;
}
