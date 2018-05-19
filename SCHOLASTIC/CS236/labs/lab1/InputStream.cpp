#include "InputStream.h"

using namespace std;

InputStream::InputStream(std::string fileName)
{
	currentLine = 0;
	currentLoc = 0;
	atEnd = false;
	buildString(fileName);
}


InputStream::~InputStream(){}

void InputStream::buildString(std::string fileName)
{
	// input file variable
	ifstream inputFile;
	// Our string parsing variable
	stringstream ss;
	char c;
	std::string line;
	// Open input file
	inputFile.open(fileName);
	// Read input until EOF
	while (getline(inputFile, line)) {
		ss << line << endl;
	}
	// Set string object from input file
	str = ss.str();
	// Close file
	inputFile.close();
	if (str.length() > 0) {
		currentLine++;
	}
}

void InputStream::advanceBy(int n)
{
	// Advance by n
	for (int i = 0; i < n; i++) {
		// Check if value at current location is a new line
		if (now() == '\n')	
		{
			// If so, increment line number
			currentLine++;
		}
		// Increment location idx by n
		currentLoc++;
	}
}

char InputStream::now()
{
	//  Check if we're at the end of the file
	if (currentLoc >= str.length()) {
		return '\0';
	}
	// If not, return value at current location
	else {
		return str[currentLoc];
	}
}

char InputStream::lookAhead(int i)
{
	// Check if able to look ahead
	if (currentLoc + i < str.length()) {
		return str[currentLoc + i];
	}
	else {
		return '\0';
	}
}

// Check if at end of file
bool InputStream::isAtEnd()
{
	return atEnd;
}

// Print our string obj made from input file
void InputStream::print()
{
	cout << str;
}

// What is the current location
int InputStream::getCurrentLoc()
{
	return currentLoc;
}
// What is the current line
int InputStream::getCurrentLine()
{
	return currentLine;
}


