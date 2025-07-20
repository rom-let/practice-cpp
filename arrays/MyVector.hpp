//ifdefine etc
#ifndef PRACTICE_MYVECTOR_HPP
#define PRACTICE_MYVECTOR_HPP

#include <memory> //for std::unique_ptr


namespace practice::array {
  const unsigned int BASE_CAPACITY {16};
  const unsigned int BASE_SIZE {0};
  const unsigned int BASE_MULTIPLICATOR {2}; //maybe not useful since I aim to use bitwise operation


//Vector of int
class MyVector{

public:
MyVector(unsigned int wantedCapacity);//constructor
MyVector(); //= default; //default constructor
//MyVector(const MyVector& myvector) = default; //default copy constructor
~MyVector(); //destructor
MyVector(MyVector&& myvector) noexcept; //move constructor
MyVector& operator=(const MyVector& myvector);//move assignement operator


unsigned int getSize() const;
unsigned int getCapacity() const;
bool isEmpty() const;
signed int getValue(unsigned int index) const;
void push(signed int item);
void pop();
void insert(unsigned int index,signed int item);
void prepend(int item);
void deleteAtIndex(unsigned int index);
void removeItem(int item);//can remove multiple items of same value
signed int find(int item) const; // return first index with item value


//protected:

private:
unsigned int capacity_{BASE_CAPACITY};
unsigned int size_{BASE_SIZE}; 
std::unique_ptr<int[]> data_; //array where int are stored

void setCapacity(unsigned int wantedCapacity);
//resize capacity based on size
// should it exists ?
// sort of a check capacity
void resizeCapacity(); //use binary calculation, log2() and bit shift
void increaseCapacity();
void decreaseCapacity();
bool isValidIndex(unsigned int index);
};

}// namespace practice::array

#endif // PRACTICE_MYVECTOR_HPP
