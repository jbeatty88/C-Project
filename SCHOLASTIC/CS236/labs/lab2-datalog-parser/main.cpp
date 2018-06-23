#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <exception>
#include "Lexer.h"

using namespace std;

int main(int argc, char** argv) 
{
	// Verify argument was given
	if(argc < 2) {
		throw invalid_argument("Please enter a file name!");
	}

	Lexer lexer(argv[1]);
	lexer.tokenize();
	lexer.printV();
	return 0;

}
