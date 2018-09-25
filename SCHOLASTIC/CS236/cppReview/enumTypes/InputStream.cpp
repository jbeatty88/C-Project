#include "InputStream.h"

InputStream::InputStream(std::string fileName): inFile(fileName) {
  //std::cout << "Creating instance of Input stream" << std::endl;
  MakeInputVec();
};

InputStream::~InputStream(){ /*std::cout << "Deleting InputSTream Object" << std::endl;*/ };

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
