

#include "InputStream.h"

InputStream::InputStream(std::string fileName) : file(fileName) {
    currentIdx = 0;
    currentLine = 0;
    MakeVector(file);
    // PrintVector();
}

InputStream::~InputStream() {}

char InputStream::Current() { return inVec[currentLine][currentIdx]; }

char InputStream::Next(size_t n) { 
    if((inVec[currentLine].length() - currentIdx) < n) {
        size_t line(currentLine + 1);
        n = n - (inVec[currentLine].length() - currentIdx);
        Next(n);
        return inVec[line][n];
    }
    else {
        return inVec[currentLine][currentIdx + n];
    }
}

char InputStream::NextLine() { return inVec[currentLine + 1][0]; }

char InputStream::Before(size_t n) { return inVec[currentLine][currentIdx - n]; }

bool InputStream::IsEnd() { return isEnd; }

size_t InputStream::GetCurrentIdx() { return currentIdx; }

size_t InputStream::GetCurrentLine() { return currentLine + 1; }

size_t InputStream::GetCurrentLength() { return inVec[currentLine].length(); }

size_t InputStream::GetVecSize() { return inVec.size(); }

void InputStream::MakeVector(std::string fileName) {
    std::ifstream inFile(fileName);
    std::string line;
    while(getline(inFile, line)) 
        inVec.push_back(line);
}

void InputStream::AdvanceBy(size_t a) {
    for(size_t i = 0; i < a; i++) {
        if(inVec[currentLine].length() < a) {
            size_t idx = a - inVec[currentLine].length();
            currentLine++;
            AdvanceBy(idx);
        }
        else if(inVec[currentLine].length() == a) {
            currentLine++;
            currentIdx = 0;
            i+= a;
        }
        else{
            if(inVec[currentLine].length() - (currentIdx + 1) == 0) {
                currentLine++;
                currentIdx = 0;
                //AdvanceBy(a);
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