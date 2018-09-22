#pragma once

#include <iostream>
#include <fstream>
#include <vector>


class InputStream {
 private:
  std::string line;
  std::ifstream inFile;
  std::string fileName;
 protected:
  std::vector<std::string> inputVec;
 public:
  InputStream(std::string fileName);
  ~InputStream();
  int GetVecSize();
  void PrintVec();
  std::vector<std::string> MakeInputVec();
  
};
