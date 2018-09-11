#include "class.h"

double Box::getVolume(void) {
  return length * height * breadth;
  
}

void Box::setLength(double len) {
  length = len;
}

void Box::setHeight(double hei) {
  height = hei;
}

void Box::setBreadth(double bre) {
  breadth = bre;
}
