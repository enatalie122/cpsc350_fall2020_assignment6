/*
* Natalie Ewing
* 2313895
* ewing@chapman.edu
* CPSC 350-01
* Assignment 6: Sorting
*/

//sorting_algorithms.h is the header file for the SortingAlgorithms class

#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS

#include <iostream>
#include <time.h>

using namespace std;

//The SortingAlgorithms class sorts user provided data using various common sorting algorithms.
class SortingAlgorithms{
public:
  /*Default Constructor: SortingAlgorithms
  * Initializes emoty arrays of size 10, and sets arraySize to 10.
  */
  SortingAlgorithms();

  /*Overloaded Constructor:
  * Initializes arrays to the contents of a user file, and sets arraySize accordingly.
  */
  SortingAlgorithms(string fileContents);

  /*Destructor: ~SortingAlgorithms
  * Deletes the arrays unsortedValues and values.
  */
  ~SortingAlgorithms();

  /*Member Function: BubbleSort
  * A sorting algorithm that iterates through a list, comparing and swapping adjacent
  * elements if the second element is less than the first element.
  */
  void BubbleSort();

  /*Member Function: SelectionSort
  * A sorting algorithm that treats the input as two parts, a sorted part and an unsorted part,
  * and repeatedly selects the proper next value to move from the unsorted part to the end of the sorted part.
  */
  void SelectionSort();

  /*Member Function: InsertionSort
  * A sorting algorithm that treats the input as two parts, a sorted part and an unsorted part, and repeatedly
  * inserts the next value from the unsorted part into the correct location in the sorted part.
  */
  void InsertionSort();

  /*Member Function: QuickSort
  * Calls the QuickSort algorithm and passes in the lowest and highest indices of the data to be sorted.
  */
  void QuickSort();

  /*Member Function: MergeSort
  * Calls the MergeSOrt algorithm and passes in the first and last indices of the data to be sorted.
  */
  void MergeSort();

private:
  /*Helper Function: Partition
  * Partitions data to be sorted in the QuickSort function.
  * Parameters:
  * lowIndex: an int representing the index to the left of the data being sorted.
  * highIndex: an int representing the index to the right of the data being sorted.
  * Returns: an int the current value of highIndex.
  */
  int Partition(int lowIndex, int highIndex);

  /*Helper Function: QuickSort
  * A sorting algorithm that repeatedly partitions the input into low and high parts (each part unsorted),
  * and then recursively sorts each of those parts.
  * Parameters:
  * lowIndex: an int representing the index to the left of the data being sorted.
  * highIndex: an int representing the index to the right of the data being sorted.
  */
  void QuickSort(int lowIndex, int highIndex);

  /*Helper Function: Merge
  * Merges the two sorted partitions into a single list by repeatedly selecting the smallest element from
  * either the left or right partition and adding that element to a temporary merged list.
  * Parameters:
  * i: an int representing the index of first element in the list
  * j: an int used to divide the list into two halves
  * k: an int representing the index of the last element
  */
  void Merge(int i, int j, int k);

  /*Helper Function: MergeSort
  * A sorting algorithm that divides a list into two halves, recursively sorts each half, and then merges
  * the sorted halves to produce a sorted list.
  * Parameters:
  * i: an int representing the index of first element in the list
  * k: an int representing the index of the last element
  */
  void MergeSort(int i, int k);

  /*Helper Function: InitializeArrays
  * Initializes unsortedValues and values to the contents of a user provided file
  * Parameters:
  * fileContents: a string representing the data from a file
  */
  void InitializeArrays(string fileContents);

  /*Helper Function: ResetArray
  * Copies the contents of the unsorted array to the array that has been previously sorted.
  */
  void ResetArray();

  /*Member Variable: *unsortedValues
  * A pointer to an array of doubles representing the unsorted data provided by the user.
  */
  double *unsortedValues;

  /*Member Variable: *values
  * A pointer to an array of doubles that can be repeatedly sorted using the various sorting algorithms.
  */
  double *values;

  /*Member Variable: arraySize
  * An int representing the number of values the user has provided to be sorted.
  */
  int arraySize;

  /*Member Variable: currentTime
  * A time_t representing the current timestamp when an algorithm starts or finishes.
  */
  time_t currentTime;

};
#endif
