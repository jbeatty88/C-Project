#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//#include <vector>

class InputStream
{
private:
	//std::vector<std::string> inVec;
	std::string str;
	size_t currentPos = 0;
	size_t currentLine = 0;
	bool isEnd = false;
public:
	InputStream(std::string fileName);
	~InputStream();
	void MakeInputString(std::string fileName);
	void AdvanceBy(size_t n);
	char Current();
	char Next(size_t i);
	bool IsEnd();
	void PrintString();
	size_t GetCurrentPos();
	size_t GetCurrentLine();
	size_t GetCurrentIdx();
	// size_t GetCurrentLine();
	// size_t GetCurrentLineIdx();
	// size_t GetCurrentLength();
	// size_t GetVecSize();
	//void PrintVec(std::vector<std::string> stringVec);
};
