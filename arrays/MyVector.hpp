//ifdefine etc
#ifndef PRACTICE_MYVECTOR_HPP
#define PRACTICE_MYVECTOR_HPP

#include <memory> //for std::unique_ptr


namespace practice::array {
  //should I write static ?
  static const unsigned int BASE_CAPACITY {16};
  static const unsigned int BASE_SIZE {0};
  static const unsigned int BASE_MULTIPLICATOR {2}; //maybe useless -> use bitwise operation


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
void prepend(signed int item);
void deleteAtIndex(unsigned int index);
void removeItem(signed int item);//can remove multiple items of same value
unsigned int find(signed int item) const; // return first index with item value
void updateValue(unsigned int index, signed int item);

//protected:

private:
unsigned int capacity_{BASE_CAPACITY};
unsigned int size_{BASE_SIZE}; 
std::unique_ptr<signed int[]> data_; //array where int are stored

void setCapacity(unsigned int wantedCapacity);
void resizeCapacity();
void increaseCapacity();
void decreaseCapacity();
bool isValidIndex(unsigned int index) const;
};

}// namespace practice::array

#endif // PRACTICE_MYVECTOR_HPP
