/*
* Natalie Ewing
* 2313895
* ewing@chapman.edu
* CPSC 350-01
* Assignment 6: Sorting
*/

#include "file.h"
#include "sorting_algorithms.h"
#include "errors.h"

int main(int argc, char** argv){
  string fileName = argv[1];            //get file name from command line
  File *userFile = new File();
  Errors *errorChecker = new Errors();
  userFile->set_file_name(fileName);
  bool wasRead = userFile->ReadFile();
  int userChoice;

  while (wasRead == false){   //if the file could not be opened
    cout << "Unable to open file. Would you like to: " << endl;
    cout << "1. Try another file." << endl;
    cout << "2. Generate a file." << endl;
    cout << "Enter 1 or 2: ";
    int i = 0;
    userChoice = 0;
    while(userChoice != 1 && userChoice != 2){
      userChoice = errorChecker->CheckIntInput(i, "Enter 1 or 2: ");    //ensures the user enters valid input
      i++;
    }
    if(userChoice == 1){               //tries to read a new user provided file
      cout << "Enter file name: ";
      string newFile = "";
      getline(cin, newFile);
      cout << endl;
      userFile->set_file_name(newFile);
      wasRead = userFile->ReadFile();
    } else {                              //generates random data to a file for the user to test
      cout << "Enter how many values you wish to generate: ";
      userChoice = 0;
      i = 0;
      while(userChoice < 1){
        userChoice = errorChecker->CheckIntInput(i, "Enter an int greater than 0: ");
        ++i;
      }
      userFile->WriteFile(userChoice);
      userFile->set_file_name("data.txt");
      wasRead = userFile->ReadFile();
    }
  }

  string fileContents = userFile->get_file_contents();


  //test how long each sorting method takes
  SortingAlgorithms *s = new SortingAlgorithms(fileContents);
  s->BubbleSort();
  cout << endl;
  s->SelectionSort();
  cout << endl;
  s->InsertionSort();
  cout << endl;
  s->QuickSort();
  cout << endl;
  s->MergeSort();
  cout << endl;

  delete s;
  delete userFile;
  delete errorChecker;
  return 0;
}
