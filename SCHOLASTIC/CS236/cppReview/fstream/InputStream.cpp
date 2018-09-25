#include "InputStream.h"

InputStream::InputStream(std::string fileName) {
  std::cout << "creating an INPUT STREAM object" << std::endl;
  std::ifstream inFile(fileName);
  while(inFile.good()) {
    std::getline(inFile, this->line);
    fileVec.push_back(this->line);
  }
  //std::cout << fileName << std::endl;
};

InputStream::~InputStream(){
  std::cout << "Destroying object" << std::endl;
};

void InputStream::PrintVec() {
  for(std::vector<std::string>::iterator it = fileVec.begin(); it != fileVec.end(); ++it) {
    std::cout << ' ' << *it << std::endl;
  }
}

int InputStream::GetVecSize() {
  return fileVec.size();
}
