#include "q2arrays.h"

//constructs with a set size
Array::Array(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];  // Increase capacity as needed
}

// Destructor to free mem
Array::~Array() {
    delete[] arr;
}

// check to find int, returing index if found
int Array::findInteger(int value) const {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;  // returning index
        }
    }
    return -1;  // Return -1 if value is not found
}

// Modifys array
int Array::modifyInteger(int index, int newValue) {
    if (index < 0 || index >= size) {
        throw IndexOutOfBoundsException("Index out of bounds for modifyInteger.");
    }
    int oldValue = arr[index];
    arr[index] = newValue;
    return oldValue;
}
//add int to end of array
int Array::addInteger(int value) {
    if (size >= capacity) {
        throw ArrayFullException("Array is full. Cannot add new integer.");
    }
    arr[size++] = value;
    return size;
}
//Removes/replaces value at index

//set as a bool to keep in one function
bool Array::replaceOrRemove(int index, bool replaceWithZero) {
    if (index < 0 || index >= size) {
        return false;  // checks if index is valid
    }
    if (replaceWithZero) {
        arr[index] = 0;  // Replace with 0
    } else {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];  //shifts elements to remove
        }
        --size; 
    }
    return true;
}

// prints array
void Array::printArray() const {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// gets size of array
int Array::getSize() const {
    return size;
}

