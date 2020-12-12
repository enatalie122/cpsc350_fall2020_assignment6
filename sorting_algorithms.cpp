/*
* Natalie Ewing
* 2313895
* ewing@chapman.edu
* CPSC 350-01
* Assignment 6: Sorting
*/

//sorting_algorithms.cpp is the implementation file for the SortingAlgorithms class

#include "sorting_algorithms.h"

SortingAlgorithms::SortingAlgorithms(){
  unsortedValues = new double[10];
  values =  new double[10];
  arraySize = 10;
}

SortingAlgorithms::SortingAlgorithms(string fileContents){
  InitializeArrays(fileContents);
}

SortingAlgorithms::~SortingAlgorithms(){
  delete[] unsortedValues;
  delete[] values;
}

void SortingAlgorithms::BubbleSort(){
  ResetArray();    //resets data to original order in case it has already been sorted
  cout << "Bubble Sort: " << endl;
  currentTime = time(NULL);
  cout << "Start Time: " << ctime(&currentTime);

  for(int i = 0; i < arraySize - 1; ++i){
    for(int j = 0; j < arraySize - 1; ++j){  //iterates through all adjacent pairs
      if(values[j] > values[j + 1]){   //if an element at j is larger than it's successor, the elements are swapped
        double temp = values[j];
        values[j] = values[j + 1];
        values[j + 1] = temp;
      }
    }
  }

  currentTime = time(NULL);
  cout << "Finish Time: " << ctime(&currentTime);
}

void SortingAlgorithms::SelectionSort(){
  ResetArray();
  cout << "Selection Sort: " << endl;
  currentTime = time(NULL);
  cout << "Start Time: " << ctime(&currentTime);

  for(int i = 0; i < arraySize - 1; ++i){
    int smallestIndex = i;                      // Find index of smallest remaining element
    for(int j = i + 1; j < arraySize; ++j){
      if(values[j] < values[smallestIndex]){
        smallestIndex = j;
      }
    }
    double temp = values[i];                      // Swap values[i] and values[smallestIndex]
    values[i] = values[smallestIndex];
    values[smallestIndex] = temp;
  }

  currentTime = time(NULL);
  cout << "Finish Time: " << ctime(&currentTime);
}

void SortingAlgorithms::InsertionSort(){
  ResetArray();
  cout << "Insertion Sort: " << endl;
  currentTime = time(NULL);
  cout << "Start Time: " << ctime(&currentTime);

  double temp;                                     // Temporary variable for swap
  for(int i = 1; i < arraySize; ++i){
    int j = i;
    // Insert values[i] into sorted part
    // stopping once values[i] in correct position
    while(j > 0 && values[j] < values[j - 1]){
      temp = values[j];                 // Swap values[j] and values[j - 1]
      values[j] = values[j - 1];
      values[j - 1] = temp;
      --j;
    }
  }

  currentTime = time(NULL);
  cout << "Finish Time: " << ctime(&currentTime);
}

int SortingAlgorithms::Partition(int lowIndex, int highIndex){
  // Pick middle element as pivot
  int midpoint = lowIndex + (highIndex - lowIndex) / 2;
  double pivot = values[midpoint];
  bool done = false;

  while(!done){
    // Increment lowIndex while values[lowIndex] < pivot
    while(values[lowIndex] < pivot){
      lowIndex++;
    }
    // Decrement highIndex while pivot < values[highIndex]
    while(pivot < values[highIndex]){
      highIndex--;
    }
    // If zero or one elements remain, then all numbers are
    // partitioned. Return highIndex.
    if(lowIndex >= highIndex){
      done = true;
    } else {     // Swap numbers[lowIndex] and numbers[highIndex]
      double temp = values[lowIndex];
      values[lowIndex] = values[highIndex];
      values[highIndex] = temp;

      lowIndex++;    // Update lowIndex and highIndex
      highIndex--;
    }
  }
  return highIndex;
}

void SortingAlgorithms::QuickSort(int lowIndex, int highIndex){
  // Base case: If the partition size is 1 or zero
  // elements, then the partition is already sorted
  if(lowIndex >= highIndex){
    return;
  }

  // Partition the data within the array. Value lowEndIndex
  // returned from partitioning is the index of the low
  // partition's last element.
  int lowEndIndex = Partition(lowIndex, highIndex);

  // Recursively sort low partition (lowIndex to lowEndIndex)
  // and high partition (lowEndIndex + 1 to highIndex)
  QuickSort(lowIndex, lowEndIndex);
  QuickSort(lowEndIndex + 1, highIndex);
}

void SortingAlgorithms::QuickSort(){
  ResetArray();
  cout << "Quick Sort: " << endl;
  currentTime = time(NULL);
  cout << "Start Time: " << ctime(&currentTime);

  QuickSort(0, arraySize - 1);

  currentTime = time(NULL);
  cout << "Finish Time: " << ctime(&currentTime);
}

void SortingAlgorithms::Merge(int i, int j, int k){
  int mergedSize = k - i + 1;                         // Size of merged partition
  int mergePos = 0;                                   // Position to insert merged number
  int leftPos = 0;                                    // Position of elements in left partition
  int rightPos = 0;                                   // Position of elements in right partition
  double *mergedNumbers = new double[mergedSize];     // Dynamically allocates temporary array for merged numbers

  leftPos = i;                                        // Initialize left partition position
  rightPos = j + 1;                                   // Initialize right partition position

  while(leftPos <= j && rightPos <= k){               // Add smallest element from left or right partition to merged numbers
    if(values[leftPos] <= values[rightPos]){
      mergedNumbers[mergePos] = values[leftPos];
      ++leftPos;
    } else {
      mergedNumbers[mergePos] = values[rightPos];
      ++rightPos;
    }
    ++mergePos;
  }
  while(leftPos <= j){                                // If left partition is not empty, add remaining elements to merged numbers
    mergedNumbers[mergePos] = values[leftPos];
    ++leftPos;
    ++mergePos;
  }

  while(rightPos <= k){                               // If right partition is not empty, add remaining elements to merged numbers
    mergedNumbers[mergePos] = values[rightPos];
    ++rightPos;
    ++mergePos;
  }

  for(mergePos = 0; mergePos < mergedSize; ++mergePos){    // Copy merge number back to values
    values[i + mergePos] = mergedNumbers[mergePos];
  }
}

void SortingAlgorithms::MergeSort(int i, int k){
  int j = 0;

  if(i < k){
    j = (i + k) / 2;              // Find the midpoint in the partition
    MergeSort(i, j);              // Recursively sort left and right partitions
    MergeSort(j + 1, k);
    Merge(i, j, k);               // Merge left and right partition in sorted order
  }
}

void SortingAlgorithms::MergeSort(){
  ResetArray();
  cout << "Merge Sort: " << endl;
  currentTime = time(NULL);
  cout << "Start Time: " << ctime(&currentTime);

  MergeSort(0, arraySize - 1);

  currentTime = time(NULL);
  cout << "Finish Time: " << ctime(&currentTime);

}

void SortingAlgorithms::InitializeArrays(string fileContents){
  int endlPosition = fileContents.find_first_of('\n');          //finding length of line to parse
  arraySize = stoi(fileContents.substr(0, endlPosition + 1));   //first line of file contains number of elements

  unsortedValues = new double[arraySize];
  values = new double[arraySize];

  int startPosition;
  for(int i = 0; i < arraySize; ++i){                           //parsing each line of string containing user data 
    startPosition = endlPosition + 1;
    endlPosition = fileContents.find_first_of('\n', startPosition);
    unsortedValues[i] = stod(fileContents.substr(startPosition, endlPosition + 1));
    values[i] = stod(fileContents.substr(startPosition, endlPosition + 1));
  }
}

void SortingAlgorithms::ResetArray(){
  for(int i = 0; i < arraySize; ++i){
    values[i] = unsortedValues[i];
  }
}
