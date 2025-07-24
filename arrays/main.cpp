#include <cassert> // for assert
#include <cstdlib> // for std::abort
#include "MyVector.hpp"
#include <iostream>

//TODO For next data structure, try to test with gtest
int main (/*int argc, char* argv[]*/){
  practice::array::MyVector testingVector(25);

  //assert constructor behavior
  assert(testingVector.getSize() == 0);
  assert(testingVector.getCapacity() == 32);
  assert(testingVector.isEmpty());

  //testing push and getValue in pair
  testingVector.push(0);
  assert(testingVector.getValue(0) == 0);

  //testing isEmpty behavior when more than one int
  testingVector.updateValue(0, 2);
  testingVector.prepend(0);
  assert(!testingVector.isEmpty());

//testing behavior of previously used methods
  testingVector.insert(1, 1);
  assert(testingVector.getValue(0) == 0);
  assert(testingVector.getValue(1) == 1);
  assert(testingVector.getValue(2) == 2);
  assert(testingVector.getValue(3) == testingVector.getSize());

  //asserting capacity and size behave like conceived
  assert(testingVector.getCapacity() == 16);
  assert(testingVector.getSize() == 3);
  for (signed int i {testingVector.getSize()} ,  end {(3*practice::array::BASE_CAPACITY+testingVector.getSize())} ; i < end ; i++){
    std::cout << i << std::endl << end <<std:: endl << std::endl;
    testingVector.push(i);
    std::cout << testingVector.getValue(i) << std::endl << std::endl << std::endl;
  }
  assert(testingVector.getCapacity() == 64);
  //std::cout << testingVector.getSize() << std::endl;
  assert(testingVector.getSize() == 51);//expected 51

  testingVector.pop();
 // assert(testingVector.getValue(testingVector.getSize()-1) == 49);
  //std::cout << testingVector.getValue(testingVector.getSize()-1) << std::endl;

  // wrong behavior of deleteAtIndex
  testingVector.deleteAtIndex(10);

  assert(testingVector.getSize() == 49);
  //std::cout << testingVector.getValue(2) << std::endl;
  for (signed int i {0}; i<testingVector.getSize(); i++){
  std::cout << testingVector.getValue(i) << std::endl;
  }
  assert(testingVector.getValue(10) == 11);
  assert(testingVector.getValue(5) == 5);

  testingVector.insert(10, 5);
  testingVector.removeItem(5);
  for (signed int i {0}; i<testingVector.getSize(); i++){
  std::cout << testingVector.getValue(i) << std::endl;
  }
  assert(testingVector.getValue(8) == 9);
  assert(testingVector.getValue(12) == 14);
  return 0;
}


/*
Since I use a lot of unsigned / signed int
and Casting everywhere, maybe I should test
when numbers are very high (or reduce max
size of int for this specific test)

in doubt, I will use only signed int


indexes of an array are automatically unsigned long int, how to avoid warnings ? check doc
*/