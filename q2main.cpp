
#include "q2arrays.h"
#include <iostream>
using namespace std;

int main() {
     //basic construction 
  const int MAX_SIZE = 105;
  Array arr(MAX_SIZE);
    //takes data from input file into array
    //file handling
  ifstream inputFile("data.txt");
  if (!inputFile) {
    cerr << "Error opening file.\n" << endl;
    return 1;
  }

  int value;
  while (inputFile >> value) {
    try {
      arr.addInteger(value);
    } catch (const ArrayFullException &e) {
      cerr << e.what() << endl;
      break;
    }
  }
  inputFile.close();//close when done
    //test
    //arr.printArray();

  int valueToFind = 25;
    //changable, modify index 
  int index = arr.findInteger(valueToFind);
  if (index != -1) {// if successfully found index, 
    cout << "Value " << valueToFind << " found at index " << index << ".\n"
         << endl;
  } else {//if could not find, relay to user
    cout << "Value " << valueToFind << " not found in the array.\n" << endl;
  }

  int indexToModify = 5;
  int newValue = 1;
  try {// if it can fit in size, add to array
    int oldValue = arr.modifyInteger(indexToModify, newValue);
    cout << "Modified value at index " << indexToModify << " from " << oldValue
         << " to " << newValue << ".\n"
         << endl;
  } catch (const IndexOutOfBoundsException &e) {// if it can't fit into the array, relay that to the user using catch 
    cerr << e.what() << endl;
  }

  int valueAdd = 1;
  try { 
    arr.addInteger(valueAdd);
    cout << "Added value " << valueAdd << " to the array.\n" << endl;
  } catch (const ArrayFullException &e) { //catch incase array is full 
    cerr << e.what() << endl;
  }
     //For the following 2 functions, bool is used to replace as 0 or to remove, true is to replace, false is to remove
  int indexToReplaceOrRemove = 50;
  if (arr.replaceOrRemove(indexToReplaceOrRemove, true)) { //if it can be replaced, do so
    cout << "Replaced value at index " << indexToReplaceOrRemove << " with 0.\n"
         << endl;
  } else {
    cout << "Failed to replace value (invalid index).\n" << endl;
  }
  indexToReplaceOrRemove = 99;
  if (arr.replaceOrRemove(indexToReplaceOrRemove, false)) {
    cout << "Removed value at index " << indexToReplaceOrRemove << ".\n"
         << endl;
  } else {
    cout << "Failed to remove value (invalid index).\n" << endl;
  }
    //print final array
  cout << "Final array: " << endl;
  arr.printArray();
}