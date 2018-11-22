#include "InputStream.h"

InputStream::InputStream(std::string fileName) { MakeInputString(fileName); }

InputStream::~InputStream(){}

void InputStream::MakeInputString(std::string fileName) {
	// Declare input file var initialized with user fileName
	std::ifstream inputFile(fileName);
	// Our string parsing variable
	std::stringstream ss;

	std::string line;
	// Read input until EOF
	while (std::getline(inputFile, line)) {
		ss << line << std::endl;
	}
	// Set string object from input file
	//PrintVec(inVec);
	str = ss.str();
	//std::cout << str << std::endl;
}

void InputStream::AdvanceBy(size_t n) {
	// Advance by n
	for (size_t i = 0; i < n; i++) {
		// Check if value at current location is a new line
		if (Current() == '\n')
			// If so, increment line number
			currentLine++;
		// Increment location idx by n
		currentPos++;
	}
}

char InputStream::Current() {
	//  Check if we're at the end of the file
	if (currentPos > str.length()) // Should this be >= or just >, I guess i'll find out
		return '\0';
	
	// If not, return str value at current location
	else 
		return str[currentPos];
	
}

char InputStream::Next(size_t i) {
	// Check if able to look ahead
    if (currentPos + i <= str.length()) 
		return str[currentPos + i];
	else 
		return '\0';
}

// Check if at end of file
bool InputStream::IsEnd() { return isEnd; }

// Prsize_t our string obj made from input file
void InputStream::PrintString() { std::cout << str; }

// What is the current location
size_t InputStream::GetCurrentPos() { return currentPos; }

// What is the current line
size_t InputStream::GetCurrentLine() { return currentLine; }

// Print a vector of strings
/*void InputStream::PrintVec(std::vector<std::string> stringVec) 
{
	//for(std::vector<std::string>::iterator itr = stringVec.begin(); itr != stringVec.end(); ++itr)
		//std::cout << ' ' << *itr << std::endl;
}*/
