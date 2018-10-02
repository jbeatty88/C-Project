

#include "InputStream.h"

InputStream::InputStream(std::string fileName) : file(fileName) {
    // Initialize variables
    currentIdx = 0;
    currentLine = 0;
    // Make a string vector. Each item in the vector is a line from input
    MakeVector(file);
    //PrintVector();
}

InputStream::~InputStream() {}

char InputStream::Current() { return inVec[currentLine][currentIdx]; }

char InputStream::Next(size_t onwardSpaces) { 
    if(currentIdx + onwardSpaces <= inVec[currentLine].length()) {
        return inVec[currentLine][currentIdx + onwardSpaces];
    }
    else {
        return '\0';
    }
    // //FIXME: THE ISSUE WITH BLOCK COMMENTS MIGHT BE HERE
    // // Adding <= gets whole block comment but seg faults 
    // size_t leftOverSpace = (inVec[currentLine].length() - currentIdx);
    // // If we want to look past this line
    // if(leftOverSpace < onwardSpaces) { 
    //     // get next line idx
    //     size_t line(currentLine + 1);
    //     // get new onwardSpaces number
    //     onwardSpaces = onwardSpaces - leftOverSpace;
    //     // rerun algorithm with updated onwardSpaces
    //     Next(onwardSpaces);
    //     // return value on correct line and idx
    //     return inVec[line][onwardSpaces];
    // }
    // // If we want to look just on the current line
    // else 
    //     // return the char at that inx
    //     return inVec[currentLine][currentIdx + onwardSpaces];
    
}

char InputStream::NextLine(size_t nLines) { return inVec[currentLine + nLines][0]; }

char InputStream::Before(size_t backIdx) { return inVec[currentLine][currentIdx - backIdx]; }

bool InputStream::IsEnd() { return isEnd; }

size_t InputStream::GetCurrentIdx() { return currentIdx; }

size_t InputStream::GetCurrentLine() { return currentLine + 1; }

size_t InputStream::GetCurrentLength() { return inVec[currentLine].length() - 1; }

std::string InputStream::GetLineString(size_t nLine) { return inVec[nLine]; }

size_t InputStream::GetVecSize() { return inVec.size(); }

void InputStream::MakeVector(std::string fileName) {
    std::ifstream inFile(fileName);
    std::string line;
    if(inFile.peek() == EOF) {
        std::cout << "(EOF,\"\",1)\n";
        std::cout << "Total Tokens = 1\n";
        exit(1);
    }
    else {
        // While there is still somthing to get in the file
        while(getline(inFile, line)) {
        // push it to the string vector
        line += '\n';
        inVec.push_back(line);
        }
    }
    
}

void InputStream::AdvanceBy(size_t a) {
    for(size_t i = 0; i < a; i++) {
        if(inVec[currentLine][currentIdx] == '\n') {
            currentLine++;
        }
        currentIdx++;
    }
}

void InputStream::PrintVector() {
    std::vector<std::string>::iterator itr;
    for(itr = inVec.begin(); itr != inVec.end(); ++itr) 
        std::cout << ' ' << *itr << std::endl;
}

void InputStream::SetCurrentPos(size_t line, size_t idx) { 
    currentLine += line;
    currentIdx = idx;
}

void InputStream::SetCurrentIdx(size_t n) { currentIdx += n; }