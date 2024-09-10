#include <iostream>
#include <fstream>
using namespace std;
// I believe we were asked in class to overwrite our array function instead of
// using the default one given by C++. If that's not right, ignore the class and
// just create the built-in array functions as standalone functions, as it would
// work similarly.
class Array {
private:
  int *arr;     // pointer to array
  int size;     // size of array
  int capacity; // max size of array

public:
  // constructor with capacity
  Array(int capacity);
  // destructor
  ~Array();
  // Function to check if a certain integer exists in the array
  int findInteger(int value) const;
  // INPUT: The array, the array size, and the value to find
  // OUTPUT: The location of the value in the array, if in it

  int modifyInteger(int index, int newValue);
  // INPUT: The array, the index of the value to change, the new value, and the
  // old value
  // OUTPUT: The array with the changed value at the index

  int addInteger(int value);
  // INPUT: The array, the size of the array, the max size of the array, and the
  // value to add
  // OUTPUT: The array with the new value added

  bool replaceOrRemove(int index, bool replaceWithZero);
  // INPUT: The array, the size of the array, the index of the value to change,
  // and whether to replace or remove
  // OUTPUT:Either replaces or removes the value at the index

  void printArray() const;
  // prints array contents

  int getSize() const;
  // gets size of array
};

//Q2 additions
class IndexOutOfBoundsException : public runtime_error {
public:
    explicit IndexOutOfBoundsException(const string& message)
        :runtime_error(message) {}
};

class ArrayFullException : public runtime_error {
public:
    explicit ArrayFullException(const string& message)
        : runtime_error(message) {}
};