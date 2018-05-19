#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "Lexer.h"

using namespace std;
/*
bool hasInput(int arg_count) {
	return (arg_count > 1) ? true : false;
}*/

int main(/*int argc, char* argv[]*/) {
	/*if (!hasInput(argc)) {
		cout << "No file name entered. Exiting...";
		return -1;
	}*/

	Lexer lexer(/*argv[1]*/ "input.txt");
	lexer.tokenize();
	lexer.printV();

	system("pause");
	return 0;
} 