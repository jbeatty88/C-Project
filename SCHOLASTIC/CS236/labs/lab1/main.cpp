#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "Lexer.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cout << "Please enter file name!";
		return -1;
	}

	Lexer lexer(argv[1]);
	lexer.tokenize();
	lexer.printV();


	return 0;
}
