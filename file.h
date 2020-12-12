/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 6: Sorting
*/

//file.h is the header file for the File class.

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;


//The File class reads processes specified files.
class File{

public:

  /* Default constructor: File
  * Sets file_name and file_contents_ to empty strings.
  */
  File();

  /*Destructor: ~File
  * Does not delete anything because no pointers are used.
  */
  ~File();

  string get_file_contents();

  /*Member function: set_file_name
  * Allows the user to set the name of a file for the File object to read.
  * Parameters:
  * file_name: a string representing the name of a file.
  */
  void set_file_name(string file_name);

  /* Member function: ReadFile
  * Opens and reads a given file, and copies it's contents to a string.
  */
  bool ReadFile();

  /* Member function: WriteFile
  * Opens and writes a specified number of random double values to a file.
  * Paramters:
  * numberOfData: an int representing the number of values the user wishes to generate. 
  */
  void WriteFile(int numberOfData);


private:
  /* Member variable: file_name_
  * A string representing the name of a file to be processed.
  */
  string file_name_;

  /*Member variable: file_contents_
  * A string representing the contents of a file.
  */
  string file_contents_;
};

#endif
