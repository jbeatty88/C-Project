

#include "InputStream.h"

InputStream::InputStream(std::string fileName) : file(fileName) {
    // Initialize variables
    currentIdx = 0;
    currentLine = 0;
    tmpIdxIncr = currentIdx;
    tmpLineIncr = currentLine;
    // Make a string vector. Each item in the vector is a line from input
    MakeVector(file);
    //PrintVector();
}

InputStream::~InputStream() {}

char InputStream::Current() { 
    if(currentIdx > inVec[currentLine].length()) {
        return '\0';
    }
    else {
        return inVec[currentLine][currentIdx];
    }
}

char InputStream::Next(size_t n) {

    if(currentIdx + n < inVec[currentLine].length()) {
        return inVec[currentLine][currentIdx + n];
    }
    else {
        if(currentLine + 1 < inVec.size()) {
            if(currentIdx + n < inVec[currentLine].length()) {
                return inVec[currentLine][currentIdx + n];
            }
            else {
                return inVec[currentLine + 1][n - (inVec[currentLine].length() - (currentIdx))];
                //currentLine++;
            }
        }
        else {
            if(currentIdx + n < inVec[currentLine].length()) {
                return inVec[currentLine][currentIdx + n];
            }
            else {
                isEnd = true;
                return '\0';
            }            
        }
    }        
}

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
        if(currentLine + 1 < inVec.size()) {
            if(inVec[currentLine][currentIdx] == '\n') {
                currentLine++;
                currentIdx = 0;
            }
            else {
                currentIdx++;
            }
        }
        else if(currentLine + 1 == inVec.size()) {
            if(inVec[currentLine][currentIdx] == '\n') {
                isEnd = true;
            }
            else {
                currentIdx++;
            }
        }
    }
}

void InputStream::PrintVector() {
    std::vector<std::string>::iterator itr;
    for(itr = inVec.begin(); itr != inVec.end(); ++itr) 
        std::cout << ' ' << *itr << std::endl;
}

void InputStream::SetCurrentPos(size_t line, size_t idx) { 
    if(line < inVec.size()) {
        currentLine = line;
        currentIdx = idx;
    }
}

void InputStream::SetCurrentIdx(size_t n) { currentIdx += n; }