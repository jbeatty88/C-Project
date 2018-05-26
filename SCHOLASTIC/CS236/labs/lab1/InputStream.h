#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class InputStream
{
private:
	std::string str;
	unsigned int currentLoc;
	unsigned int currentLine;
	bool atEnd;
public:
	InputStream(std::string fileName);
	~InputStream();
	void buildString(std::string fileName);
	void advanceBy(int n);
	char now();
	char lookAhead(int i);
	bool isAtEnd();
	void print();
	int getCurrentLoc();
	int getCurrentLine();
	//void PrintStr();
};
