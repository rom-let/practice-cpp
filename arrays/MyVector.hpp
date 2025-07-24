//ifdefine etc
#ifndef PRACTICE_MYVECTOR_HPP
#define PRACTICE_MYVECTOR_HPP

#include <memory> //for std::unique_ptr


namespace practice::array {
  //should I write static ?
  static const signed int BASE_CAPACITY {16};
  static const signed int BASE_SIZE {0};
  static const signed int BASE_MULTIPLICATOR {2}; //maybe useless -> use bitwise operation


//Vector of int
class MyVector{

public:
MyVector(signed int wantedCapacity);//constructor
MyVector(); //= default; //default constructor
//MyVector(const MyVector& myvector) = default; //default copy constructor
~MyVector(); //destructor
MyVector(MyVector&& myvector) noexcept; //move constructor
MyVector& operator=(const MyVector& myvector);//move assignement operator


signed int getSize() const;
signed int getCapacity() const;
bool isEmpty() const;
signed int getValue(signed int index) const;
void push(signed int item);
void pop();
void insert(signed int index,signed int item);
void prepend(signed int item);
void deleteAtIndex(signed int index);
void removeItem(signed int item);//can remove multiple items of same value
signed int find(signed int item) const; // return first index with item value
void updateValue(signed int index, signed int item);

//protected:

private:
signed int capacity_{BASE_CAPACITY};
signed int size_{BASE_SIZE}; 
std::unique_ptr<signed int[]> data_; //array where int are stored

void setCapacity(signed int wantedCapacity);
void resizeCapacity();
void increaseCapacity();
void decreaseCapacity();
bool isValidIndex(signed int index) const;
};

}// namespace practice::array

#endif // PRACTICE_MYVECTOR_HPP
