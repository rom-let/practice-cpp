//ifdefine etc

#include <memory> //for std::unique_ptr

//namespace

//Vector of int
class MyVector{

public:
MyVector(int capacity);//constructor
~MyVector(); //destructor

unsigned int getSize() const;
unsigned int getCapacity() const;
bool isEmpty() const;
int getValue(unsigned int index) const;
void push();
void pop();
void insert(unsigned int index, int item);
void prepend(int item);
void deleteAtIndex(unsigned int index);
void removeItem(int item);//can remove multiple items of same value
int find(int item) const; // return first index with item value


//protected:

private:
int capacity_{/*MinCapacity*/};
int size_{0}; 
std::unique_ptr<int[]> data_; //array where int are stored

void resize(unsigned int new_capacity);

void increaseCapacity();

void decreaseCapacity();
};
