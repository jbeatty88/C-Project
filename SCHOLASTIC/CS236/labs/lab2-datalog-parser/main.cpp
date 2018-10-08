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
	// if (argc == 1) {
	// 	cout << "Please enter file name!";
	// 	return -1;
	// }
	// Lexer lexer(argv[1]);
	// lexer.PrintVec();
	// Parser p(lexer.GetTokenVec()); 

	// 10 TEST CASES
	cout << "Test 1: "; 	Lexer test1("test1.txt"); 	Parser p1(test1.GetTokenVec());
	cout << "\nTest 2: "; 	Lexer test2("test2.txt");	Parser p2(test2.GetTokenVec());
	cout << "\nTest 3: "; 	Lexer test3("test3.txt");	Parser p3(test3.GetTokenVec());
	cout << "\nTest 4: "; 	Lexer test4("test4.txt");	Parser p4(test4.GetTokenVec());
	cout << "\nTest 5: "; 	Lexer test5("test5.txt");	Parser p5(test5.GetTokenVec());
	cout << "\nTest 6: "; 	Lexer test6("test6.txt");	Parser p6(test6.GetTokenVec());
	cout << "\nTest 7: "; 	Lexer test7("test7.txt");	Parser p7(test7.GetTokenVec());
	cout << "\nTest 8: "; 	Lexer test8("test8.txt");	Parser p8(test8.GetTokenVec());
	cout << "\nTest 9: "; 	Lexer test9("test9.txt");	Parser p9(test9.GetTokenVec());
	cout << "\nTest 10: "; 	Lexer test10("test10.txt");	Parser p10(test10.GetTokenVec());

	return 0;
}
