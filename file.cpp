/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 6: Sorting
*/

//file.cpp is the implementation of the File class.

#include "file.h"

File::File(){
  string file_name_ = "";
  file_contents_ = "";
}

File::~File(){}

string File::get_file_contents(){
  return file_contents_;
}

void File::set_file_name(string file_name){
  file_name_ = file_name;
}

bool File::ReadFile(){
  string line;
  ifstream file;
  while (file.is_open() == false){
    file.open(file_name_);
    if (file.is_open()){                      //proceed if we can open the file
      while (!file.eof()){
        getline(file, line);
        file_contents_ += line + '\n';
      }
      file.close();
      return true;
    } else {
      return false;
    }
  }
}

void File::WriteFile(int numberOfData){
  ofstream my_file;
  my_file.open ("data.txt");
  if (my_file.is_open()){
    my_file << numberOfData << endl;
    for(int i = 0; i < numberOfData; ++i){
      double data = rand() / (RAND_MAX + 1.0);
      my_file << data << endl;
    }
    my_file.close();
  } else {
    cout << "Unable to open file.";
  }
}
