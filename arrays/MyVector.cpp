#include "MyVector.hpp"
#include <iostream>
#include <memory>


namespace practice::array{

//public
MyVector::MyVector(unsigned int wantedCapacity){
  if(wantedCapacity > BASE_CAPACITY){
  MyVector::setCapacity(wantedCapacity);
  }// is it better to use getCapacity here or just capacity_ ? 
  std::cout << "Vector of capacity " <<  getCapacity() << " created";
}

MyVector::MyVector() {
  std::cout << "Vector of capacity " <<  getCapacity() << " created";
} 

unsigned int MyVector::getSize() const{
  return size_;
}

unsigned int MyVector::getCapacity() const{
  return capacity_;
}

bool MyVector::isEmpty() const{
  if(!MyVector::getSize())
    {return true;}
  return false;
}// try to write it in ternary expression

//should it care about out of bound ?
signed int MyVector::getValue(unsigned int index) const{
  //return data_[index];
  return *(data_.get() + index); // learn more about this
}

void MyVector::push(signed int item){
  size_ ++;
  resizeCapacity();
  *(data_.get() +size_) = item;
}

void MyVector::pop(){
  //should I erase something ? How ?
  size_ --;
  resizeCapacity();
}

void MyVector::insert(unsigned int index, signed int value){
  if(isValidIndex(index)){
  size_ ++;
  resizeCapacity();
  signed int previous_value {data_[index]};
  signed int next_value {};
  data_[index] = value;
  for(unsigned int i = index+1;i < size_-1; i++){
    next_value = data_[i];
    data_[i] = previous_value;
  }
  data_[size_-1] = previous_value;
  }
}
//private
void MyVector::setCapacity(unsigned int wantedCapacity){
  /* create a value of 1
    if it is smaller than size
    bitshift left
  */ 
  unsigned int bestCapacity {1};
  //what’s best : < or <= ?
  while (bestCapacity < wantedCapacity){
    bestCapacity <<=1; //leftshift by one on the left side
    //could be improved by using divide and conquer
  }
  capacity_ = bestCapacity;
}



void MyVector::resizeCapacity(){

}

bool MyVector::isValidIndex(unsigned int index){
  if(index >= size_){
    std::cout << "Index out of bound\n" << "operantion cancelled";
    //is it good practice ?
    return false;
  }
  return true;
}
} // namespace practice::array