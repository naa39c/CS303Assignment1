#include <iostream>
#include "arrays.h"
using namespace std; 

int main() {
    //basic construction 
    const int MAX_SIZE = 105;  // max size of the array
    Array arr(MAX_SIZE);  // creates array

    //takes data from input file into array
    //file handling
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Error opening file.\n" << endl;
        return 1;
    }

    int value;
    while (inputFile >> value) {  // reads and adds ints to array
        int newSize = arr.addInteger(value);
        if (newSize == MAX_SIZE) {
            cerr << "Array is full. Cannot add more values.\n" << endl;
            break;
        }
    }
    inputFile.close(); //close when done

    //test
    //arr.printArray();

    int valueToFind = 25;
    int index = arr.findInteger(valueToFind);
    if (index != -1) {
        cout << "Value " << valueToFind << " found at index " << index << ".\n" << endl;
    } else {
        cout << "Value " << valueToFind << " not found in the array.\n" << endl;
    }
    //changable, modify index 
    int indexToModify = 5;
    int newValue = 1;
    int oldValue = arr.modifyInteger(indexToModify, newValue);
    if (oldValue != -1) {// if successfully found index, 
        cout << "Modified value at index " << indexToModify << " from " << oldValue << " to " << newValue << ".\n" << endl;
    } else { //if could not find, relay to user
        cout << "Failed to modify value (invalid index).\n" << endl;
    }

    int valueAdd = 1;
    int newSize = arr.addInteger(valueAdd);
    if (newSize < MAX_SIZE) { // if it can fit in size, add to array
        cout << "Added value " << valueAdd << " to the array.\n" << endl;
    } else { // if it can't fit into the array, relay that to the user
        cout << "Failed to add value: "<<valueAdd<< " to the array (array might be full).\n" << endl;
    }

    //For the following 2 functions, bool is used to replace as 0 or to remove, true is to replace, false is to remove
    int indexToReplaceOrRemove = 50; //changable
    if (arr.replaceOrRemove(indexToReplaceOrRemove, true)) { //if it can be replaced, do so
        cout << "Replaced value at index " << indexToReplaceOrRemove << " with 0.\n" << endl;
    } else { //relay if it can't 
        cout << "Failed to replace value (invalid index).\n" << endl;
    }
    indexToReplaceOrRemove = 99;
    if (arr.replaceOrRemove(indexToReplaceOrRemove, false)) {
        cout << "Removed value at index " << indexToReplaceOrRemove << ".\n" << endl;
    } else {
        cout << "Failed to remove value (invalid index).\n" << endl;
    }

    arr.printArray();

    cout << "Final array: "<< endl;
    arr.printArray();
}