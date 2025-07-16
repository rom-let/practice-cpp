#include <cstdio>

int showArrayValueBasedOnIndex(int myArray[], int arrayNumber);
int showArrayValueUsingPtr(int* myArrayPtr, int arrayNumber);

int main (/*int argc, char* argv[]*/){
  int unsigned static ArraySIZE = 5;

  int myArray[ArraySIZE];
  int* myArrayPtr = myArray;
  unsigned int requiredInt = 3;
  
  for (unsigned int i = 0; i < ArraySIZE; i++){
    myArray[i] = (signed int) i+42;
  }
// myArray will be [42, 43, 44, 45, 46]

std::printf("The %i th element of the array is %i \n", requiredInt, showArrayValueBasedOnIndex(myArray, requiredInt));
std::printf("The %i th element of the array is %i \n", requiredInt+1, showArrayValueUsingPtr(myArrayPtr, requiredInt+1));


  return 0;
}

int showArrayValueBasedOnIndex(int myArray[], int arrayNumber){
  //taking in account that the user do not know c++ logic
  return myArray[arrayNumber-1];
}

int showArrayValueUsingPtr(int* myArrayPtr, int arrayNumber){

  return (*myArrayPtr + arrayNumber -1);
}
