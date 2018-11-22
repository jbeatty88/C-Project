

#include "InputStream.h"

InputStream::InputStream(std::string fileName) : file(fileName) {
    // Initialize variables
    this->currentIdx = 0;
    this->currentLine = 0;
    this->tmpIdxIncr = currentIdx;
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

char InputStream::Next(size_t n, size_t line, size_t idx) {
    // If there is space on the line
    size_t length = 0;
    length = inVec[line].length();
    size_t nextVal = 0;
    nextVal = idx + n;

    if(nextVal < length) {
        // Look at the index on that line
        return inVec[line][nextVal];
    }
    // If there is no more space on the line
    else {
        // If we are NOT at the last line of the vector
        if(line + 1 < inVec.size()) {
            return inVec[line + 1][n - ((inVec[line].length() + 1) - currentIdx)];
        }
        else {
            isEnd = true;
            return '\0';
        }
    }
}

char InputStream::NextLine(size_t nLines) { return inVec[currentLine + nLines][0]; }

char InputStream::Before(size_t backIdx) {
  if(backIdx <= currentIdx) {
    return inVec[currentLine][currentIdx - backIdx];
  }
  else {
    return inVec[currentLine][currentIdx];
  }
}

bool InputStream::IsEnd() { return isEnd; }

size_t InputStream::GetCurrentIdx() { return currentIdx; }

size_t InputStream::GetCurrentLine() { return currentLine + 1; }

size_t InputStream::GetCurrentLength() { return inVec[currentLine].length() - 1; }

std::string InputStream::GetLineString(size_t nLine) { return inVec[nLine]; }

size_t InputStream::GetVecSize() { return inVec.size(); }

void InputStream::MakeVector(std::string fileName) {
    std::ifstream inFile(fileName);
    std::string line;
    if(inFile.fail()) {
        std::cout << "Not a valid file" << std::endl;
        exit(1);
    }
    else {
      if(inFile.peek() == EOF) {
          std::cout << "(EOF,\"\",1)\n";
          std::cout << "Total Tokens = 1\n";
          exit(1);
      }
      else {
        while(getline(inFile, line)) {
        // push it to the string vector
          line += '\n';
          inVec.push_back(line);
        }
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
