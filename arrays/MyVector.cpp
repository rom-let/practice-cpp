#include "MyVector.hpp"
#include <iostream>
#include <memory>
#include <utility>


namespace practice::array{

//public

// ways to improve : 
// 1) is it better to use getCapacity here or just capacity_ ?
MyVector::MyVector(signed int wantedCapacity){
  if(wantedCapacity > BASE_CAPACITY){
  MyVector::setCapacity(wantedCapacity);
  }
  data_ = std::unique_ptr<signed int[]>(new signed int[capacity_]);
  std::cout << "Vector of capacity " <<  getCapacity() << " created\n";
}

MyVector::MyVector() {
  data_ = std::unique_ptr<signed int[]>(new signed int[capacity_]);
  std::cout << "Vector of capacity " <<  getCapacity() << " created\n";
} 

MyVector::~MyVector(){
  std::cout << "Vector destructed successfully \n";
}

signed int MyVector::getSize() const{
  return size_;
}

signed int MyVector::getCapacity() const{
  return capacity_;
}

//could be easier to read with following line
//return size_ == 0;
bool MyVector::isEmpty() const{
  return (!getSize() ? true : false);
}

//should it cares about out of bound ?
//return size_ if out of bound
signed int MyVector::getValue(signed int index) const{
  if(isValidIndex(index)){
    return (data_[index]);
  //return *(data_.get() + index); // learn more about this
  }
  return size_;
}

void MyVector::push(signed int item){
  size_ ++;
  resizeCapacity();
  // same thing as data_[size_-1] = item;
  *(data_.get() +size_-1) = item;
}

// ways to improve
// 1) should I erase something ? How ?
void MyVector::pop(){
  if(!isEmpty()){
  size_ --;
  resizeCapacity();
  }
}

void MyVector::insert(signed int index, signed int item){
  if(isValidIndex(index)){
  size_ ++;
  resizeCapacity();
  for(signed int i{size_-1};i > index; i--){
      data_[i] = data_[i-1];
  }
  data_[index] = item;
  }
}

void MyVector::prepend(signed int item){
  insert(0, item);
}

// ways to improve :
// 1) should I erase the old last value of the array ? How ?
void MyVector::deleteAtIndex(signed int index){
  if(isValidIndex(index) && !isEmpty()){
     for(signed int i {index+1}; i < size_-1; i++){
      data_[i-1]  = data_[i];
    }
    size_ --;
    resizeCapacity();
  }
}

//TODO : check online if size_ is defined as a local variable for the loop, or if it uses size_ at each iteration
void MyVector::removeItem(signed int item) {
  for(signed int i {0}; i < size_; i++){
    if(data_[i] == item){
      deleteAtIndex(i);
    }    
  }
}

// ways to improve :
// 1) find a better solution than returning an actual value, without making the program crash.
// -> maybe return the last item of the list (the very end, the \0)
signed int MyVector::find(signed int item) const{
  for(signed int i {0};i < size_; i++){
    if(data_[i]== item){
      return i;
    }
  }
  return size_;
}

void MyVector::updateValue(signed int index, signed int item){
  if(isValidIndex(index)){
      data_[index] = item;
  }
}
//private

//ways to improve :
// 1) check which one is better between <<= and <<
// 2) use divide and conquer
void MyVector::setCapacity(signed int wantedCapacity){
  signed int bestCapacity {1};
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
  if(capacity_ > BASE_CAPACITY && size_ < capacity_/BASE_MULTIPLICATOR){
    decreaseCapacity();
  }
}

void MyVector::increaseCapacity(){
  capacity_ <<= 1;
  std::unique_ptr<signed int[]> new_data (new signed int[capacity_]);
  for (signed int i{0};i <size_; i++ ){
    new_data[i] = data_[i];
  }
  data_ = std::move(new_data);
}

void MyVector::decreaseCapacity(){
  capacity_ >>=1;
  std::unique_ptr<signed int[]> new_data (new signed int[capacity_]);
  for (signed int i{0};i <size_; i++ ){
    new_data[i] = data_[i];
  }
  data_ = std::move(new_data);
}

//could use ternary operator
bool MyVector::isValidIndex(signed int index) const{
  if(index >= size_ || index < 0){
    std::cout << "Index out of bound\n" << "operantion cancelled" << std::endl;
    //is it good practice ?
    return false;
  }
  return true;
}
} // namespace practice::array