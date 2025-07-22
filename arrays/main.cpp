#include <cassert> // for assert
#include <cstdlib> // for std::abort
#include "MyVector.hpp"
//#include <iostream>

//TODO For next data structure, try to test with gtest
int main (/*int argc, char* argv[]*/){
  practice::array::MyVector testingVector(25);

  assert(testingVector.getSize() == 0);
  assert(testingVector.getCapacity() == 32);
  assert(testingVector.isEmpty());
  testingVector.push(0);
  assert(!testingVector.isEmpty());
  assert(testingVector.getValue(0) == 0);
  
  return 0;
}
