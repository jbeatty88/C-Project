#include <iostream>
#include <fstream>
#include <vector>

class InputStream {
 private:
  std::vector<std::string> fileVec;
  std::string line;
  //std::ifstream inFile(argv[1]);
  std::string fileName;
  
 public:
  //std::string fileName;
  InputStream(std::string fileName);
  ~InputStream();
  //void MakeLineVector();
  void PrintVec();
  int GetVecSize();
};
