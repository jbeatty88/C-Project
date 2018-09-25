#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(int argc, char** argv) {
  ifstream inFile(argv[1]);
  vector<string> inVec;
  string line;
  
  while(inFile) {
    getline(inFile, line);
    inVec.push_back(line);
  }

  cout << "SIZE OF VECTOR: " << inVec.size() << endl;
  cout << "\n\n\n";
  
  vector<string>::iterator itr = inVec.begin();
  
  for(itr; itr != inVec.end(); ++itr) {
    cout << *itr << endl;
  }
  
  cout << "\n\n\n";
  
  
  for(itr; itr != inVec.end(); ++itr) {
    for(unsigned int x = 0; x < inVec.size(); x++) {
      for(unsigned int y = 0; y < itr[x].size(); y++)
	cout << itr[x][y] << endl;
    }
  }

  cout << inVec[0].find('f') << endl;
  cout << inVec[0][0] << endl;
  cout << inVec[0][1] << endl;
  cout << inVec[1][0] << endl;
  cout << inVec[2][0] << endl;
  cout << inVec[2][1] << endl;
  cout << inVec[2][2] << endl;

  for(int i = 0; i != inVec.size(); i++) {
    for(int z = 0; z != inVec[i].length(); z++)
      cout << inVec[i][z] << endl;
  }


  return 0;
}
