#pragma once

#include <iostream>
#include <fstream>
#include <vector>


class InputStream {
 private:
  std::string line;
  std::ifstream inFile;
  std::string fileName;
  std::vector<std::string> inputVec;
  int currLine;
  
 public:
  InputStream(std::string fileName);
  ~InputStream();
  int GetVecSize();
  void PrintVec();
  std::vector<std::string> MakeInputVec();
  int GetCurrLine();
  
};
