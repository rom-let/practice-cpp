//ifdefine etc
#ifndef PRACTICE_MYVECTOR_HPP
#define PRACTICE_MYVECTOR_HPP

#include <memory> //for std::unique_ptr


namespace practice::array {
  const unsigned int BASE_CAPACITY = 16;
  const unsigned int BASE_SIZE = 0;
  const unsigned int BASE_MULTIPLICATOR = 2; 


//Vector of int
class MyVector{

public:
MyVector(unsigned int capacity);//constructor
~MyVector(); //destructor

unsigned int getSize() const;
unsigned int getCapacity() const;
bool isEmpty() const;
signed int getValue(unsigned int index) const;
void push();
void pop();
void insert(unsigned int index, int item);
void prepend(int item);
void deleteAtIndex(unsigned int index);
void removeItem(int item);//can remove multiple items of same value
signed int find(int item) const; // return first index with item value


//protected:

private:
unsigned int capacity_{BASE_CAPACITY};
unsigned int size_{BASE_SIZE}; 
std::unique_ptr<int[]> data_; //array where int are stored

void resize(unsigned int new_capacity);

void increaseCapacity();

void decreaseCapacity();
};

}// namespace practice::array

#endif
