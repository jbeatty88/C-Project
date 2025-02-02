#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(int argc, char**) {
  cout << "THIS IS A SHORT DEMO OF THE <map> LIBRARY" << endl;
  cout << "#########################################" << endl << endl;

  // map template requires type of key and type of value
  map <int, int> map1;

  // use .insert(pair<T, T> (item, item)) to insert things. Ex: ints
  map1.insert(pair <int, int> (1, 40));
  map1.insert(pair <int, int> (2, 50));
  map1.insert(pair <int, int> (3, 60));
  map1.insert(pair <int, int> (4, 90));
  map1.insert(pair <int, int> (5, 20));
  map1.insert(pair <int, int> (6, 10));
  map1.insert(pair <int, int> (7, 70));
  map1.insert(pair <int, int> (8, 30));

  // printing from a map is a bit tricky
  // make a map iterator
  map <int, int> :: iterator itr;
  cout << "The map is: " << endl;
  cout << "KEY ELEMENT" << endl;
  for(itr = map1.begin(); itr != map1.end(); ++itr){
    cout << itr->first << " " << itr->second << endl;
  }
  cout << endl;
  
  // asigning elements from one map to another
  cout << "Assigning elements from one existing at creation of new object. map<t, t> mapName(otherMap.begin(), otherMap.end())" << endl;
  map<int, int> map2(map1.begin(), map1.end());
  cout << "MAP 2 after the copy" << endl;
  cout << "KEY VALUE" << endl;
  for(itr = map2.begin(); itr != map2.end(); ++itr) {
    cout << itr->first << " " << itr->second << endl;
  }
  cout << endl;
  
  // removing all elements up to a certian key
  cout << "After removing all elements less than key=3: " << endl;
  map2.erase(map2.begin(), map2.find(3));
  // Once again, printing the map
  for(itr = map2.begin(); itr != map2.end(); ++itr) {
    cout << itr->first << " " << itr->second << endl;
  }
  cout << endl;
  // removing elements at a specific key
  cout << "Removing at key=4: " << endl;
  int num;
  num = map2.erase(4);
  cout << num << " - removed from map" << endl;
  for(itr = map2.begin(); itr != map2.end(); ++itr) {
    cout << itr->first << " " << itr->second << endl;
  }
  cout << endl;


  //lower bound and upper bound for map2 key = 5 
    cout << "map2.lower_bound(5) : " << "\tKEY = "; 
    cout << map2.lower_bound(5)->first << '\t'; 
    cout << "\tELEMENT = " << map2.lower_bound(5)->second << endl; 
    cout << "gquiz1.upper_bound(5) : " << "\tKEY = "; 
    cout << map2.upper_bound(5)->first << '\t'; 
    cout << "\tELEMENT = " << map2.upper_bound(5)->second << endl; 


  
  return 0;
}
