#include <iostream>
#include "inherit.h"

using namespace std;

int main(int argc, char**) {

  Parents RichAngie;
  Wife Angie("Angela", "Beatty");
  Husband Rich("Richard", "Beatty");

  RichAngie.setChildCount(4);

  cout << "KIDS: " << RichAngie.getChildCount() << endl;

  Angie.setIsMarried(1);
  Angie.getIsMarried();

  Rich.setIsMarried(0);
  Rich.getIsMarried();
  
  return 0;

}
