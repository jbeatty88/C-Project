#include <iostream>
#include "class.h"

using namespace std;

int main() {
  Box Box1;
  Box Box2;
  double volume = 0.0;

  // box 1 config
  Box1.setLength(6.0);
  Box1.setHeight(5.0);
  Box1.setBreadth(7.0);
  
  // Box 2 config
  Box2.setLength(12.0);
  Box2.setHeight(10.0);
  Box2.setBreadth(13.0);
  
  volume = Box1.getVolume();
  cout << "Volume of Box1: " << volume << endl;

  volume = Box2.getVolume();
  cout << "volume of Box2: " << volume << endl;
  
  return 0;
}
