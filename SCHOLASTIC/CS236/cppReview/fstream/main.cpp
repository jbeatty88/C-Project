#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "InputStream.h"

using namespace std;

int main(int argc, char** argv) {
  InputStream Lex(argv[1]);
  cout << "VECTOR SIZE: " <<  Lex.GetVecSize() << endl;
  Lex.PrintVec();
  
  // string fName;
  /* ifstream inFile(argv[1]);
     string line;
     stringstream ss;
     vector<string> vec;

     // CHECK FOR VALID NUM OF ARGS GIVEN
     if(argc == 1){
     cout << "Please include an input file" << endl;
     exit(0);
     }

     // OPEN THE FILE
     cout << "Now opening file: " << argv[1] << endl;
 
     if(!inFile){
     cout << "ERROR OPENING FILE" << endl;
     exit(1);
     }

     while(inFile.good()) {
     getline(inFile, line);
     vec.push_back(line);
     }
     cout << vec.size() << endl;
  for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << ' ' << *it << endl;
  }

  cout << vec[3] << endl1
  
  // cout << argv[0] << endl;
  //cout << argv[1] << endl;
  */


  return 0;
}
