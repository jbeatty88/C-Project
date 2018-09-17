#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
  // string fName;
  ifstream inFile(argv[1]);
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

  //vec.push_back(inFile);
    

  
  // cout << argv[0] << endl;
  //cout << argv[1] << endl;
  


  return 0;
}
