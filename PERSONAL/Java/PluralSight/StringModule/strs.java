/*
  NOTES
 == compares that tow items are the exact same memory address
equals() compares each value
.intern() makes sure any same values are the same memory space
Strings are immutable: Meaning any modifications makes a new strings
Stirng Builder: String manip tool; will grow dynamically however best performance when pre-size buffer
  StringBuilder sb = new StringBuilder(40)
    sb.append("Anything can go here")
    sb.insert()

Classes vs Primitives:
    Clases interact with object class. Types
    Primitive types: light weight, effecient, BUT no fields or methods, not an object. 

Primitive Wrapper class: Inherit from obj class. 
conversions btw wrapper and primiteve
     Integer a = 100;  <-----------------|
     int b = a;                          |
     Integer c = b;                      |
     Integer d = Integer.valueOf(100)    |
     int e = d.intValue();

const = static filan int

*/
