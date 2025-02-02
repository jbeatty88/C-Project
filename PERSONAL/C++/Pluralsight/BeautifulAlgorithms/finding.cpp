#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int main() {
  vector<int> v{2, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
  string s{" Hello I am a sentence" };

  // Find the first 0 in the collection
  // SYNTAX: find(Where to start looking, Where to stop looking, What to find)
  auto result = find(begin(v), end(v), 0);
  int weLookedFor = *result;

  // Find the first 2 after that 0
  result = find(result, end(v), 2);
  if(result != end(v)) {
    weLookedFor = *result;
  }

  // Find the fist a
  auto letter = find(begin(s), end(s), 'a');
  char a = *letter;

  // Find first odd value
  result = find_if(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });
  weLookedFor = *result;
  cout << "We looked for: " << weLookedFor << endl;

  //Find first even value
  result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
  weLookedFor = *result;
  cout << "We looked for: " << weLookedFor << endl;

  vector<int> primes{ 1, 2, 3, 5, 7, 11, 13 };
  result = find_first_of(begin(v), end(v), begin(primes), end(primes));
  weLookedFor = *result;
  cout << "We looked for: " << weLookedFor << endl;

  vector<int> subSeq{ 2, 4 };
  result = search(begin(v), end(v), begin(subSeq), end(subSeq));
  weLookedFor = *result;
  result++; result++;
  int six = *result;
  cout << "We looked for: " << weLookedFor << endl;

  string am = "am";
  letter = search(begin(s), end(s), begin(am), end(am));
  a = *letter;
  cout << "Letter: " << a << endl;

  result = find_end(begin(v), end(v), begin(subSeq), end(subSeq));
  result++; result++;
  if(result != end(v)) {
    weLookedFor = *result;
  }
  cout << "We looked for: " << weLookedFor << endl;

  result = search_n(begin(v), end(v), 2, 4);
  result--;
  int two = *result;

  result = adjacent_find(begin(v), end(v));
  six = *result;
  result++;
  six = *result; 

  
  return 0;
}
