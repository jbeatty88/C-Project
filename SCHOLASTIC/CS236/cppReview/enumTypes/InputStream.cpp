#include "InputStream.h"

InputStream::InputStream(std::string fileName): inFile(fileName) {
  currLine = 0;
  MakeInputVec();
};

InputStream::~InputStream(){};

int InputStream::GetVecSize() { return inputVec.size(); };

void InputStream::PrintVec() {
  for(std::vector<std::string>::iterator it = inputVec.begin(); it != inputVec.end(); ++it)
    std::cout << ' ' << *it << std::endl;
};

std::vector<std::string> InputStream::MakeInputVec() {
  while(inFile.good()) {
    std::getline(inFile, this->line);
    //this->line += '\n';
    inputVec.push_back(this->line);
  };
  
  // return a string vector. Each element is a line from input
  return inputVec;
};

int InputStream::GetCurrLine() { return currLine; };
