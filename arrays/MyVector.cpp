#include "MyVector.hpp"
#include <iostream>
#include <memory>
#include <utility>


namespace practice::array{

//public

// ways to improve : 
// 1) is it better to use getCapacity here or just capacity_ ?
MyVector::MyVector(unsigned int wantedCapacity){
  if(wantedCapacity > BASE_CAPACITY){
  MyVector::setCapacity(wantedCapacity);
  }
  data_ = std::unique_ptr<int[]>(new int[capacity_]);
  std::cout << "Vector of capacity " <<  getCapacity() << " created";
}

MyVector::MyVector() {
  data_ = std::unique_ptr<int[]>(new int[capacity_]);
  std::cout << "Vector of capacity " <<  getCapacity() << " created";
} 

unsigned int MyVector::getSize() const{
  return size_;
}

unsigned int MyVector::getCapacity() const{
  return capacity_;
}

bool MyVector::isEmpty() const{
  return (!MyVector::getSize() ? true : false);
}

//should it cares about out of bound ?
signed int MyVector::getValue(unsigned int index) const{
  //return data_[index];
  return *(data_.get() + index); // learn more about this
}

void MyVector::push(signed int item){
  size_ ++;
  resizeCapacity();
  *(data_.get() +size_) = item;
}

// ways to improve
// 1) should I erase something ? How ?
void MyVector::pop(){
  size_ --;
  resizeCapacity();
}

void MyVector::insert(unsigned int index, signed int item){
  if(isValidIndex(index)){
  size_ ++;
  resizeCapacity();
  for(unsigned int i{size_-1};i > index; i--){
      data_[i] = data_[i-1];
  }
  data_[index] = item;
  }
}

void MyVector::prepend(signed int item){
  size_ ++;
  resizeCapacity();
  for(unsigned int i{size_-1};i > 0; i--){
      data_[i] = data_[i-1];
  }
  data_[0] = item;
}

// ways to improve :
// 1) should I erase the old last value of the array ? How ?
void MyVector::deleteAtIndex(unsigned int index){
  if(isValidIndex(index)){
     for(unsigned int i {size_-1}; i > index; i--){
      data_[i-1]  = data_[i];
    }
    size_ --;
    resizeCapacity();
  }
}

//TODO : check online if size_ is defined as a local variable for the loop, or if it uses size_ at each iteration
void MyVector::removeItem(signed int item) {
  for(unsigned int i {0}; i < size_; i++){
    if(data_[i] == item){
      deleteAtIndex(i);
    }    
  }
}

// ways to improve :
// 1) find a better solution than returning an actual value, without making the program crash.
// -> maybe return the last item of the list (the very end, the \0)
signed int MyVector::find(signed int item) const{
  for(unsigned int i {0};i < size_; i++){
    if(data_[i]== item){
      return i;
    }
  }
  return 0;
}


//private

//ways to improve :
// 1) check which one is better between <<= and <<
// 2) use divide and conquer
void MyVector::setCapacity(unsigned int wantedCapacity){
  unsigned int bestCapacity {1};
  //what’s best : < or <= ?
  while (bestCapacity < wantedCapacity){
    bestCapacity <<=1;
  }
  capacity_ = bestCapacity;
}

//ways to improve
// 1) check if there is enough memory in ram ?
void MyVector::resizeCapacity(){
  if (size_ == capacity_){
    increaseCapacity();
  }
  if(size_ == capacity_/BASE_MULTIPLICATOR-1 && capacity_ > BASE_CAPACITY){
    decreaseCapacity();
  }
}

void MyVector::increaseCapacity(){
  capacity_ <<= 1;
  std::unique_ptr<int[]> new_data (new int[capacity_]);
  for (unsigned int i{0};i <size_; i++ ){
    new_data[i] = data_[i];
  }
  data_ = std::move(new_data);
}

void MyVector::decreaseCapacity(){
  capacity_ >>=1;
  std::unique_ptr<int[]> new_data (new int[capacity_]);
  for (unsigned int i{0};i <size_; i++ ){
    new_data[i] = data_[i];
  }
  data_ = std::move(new_data);
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