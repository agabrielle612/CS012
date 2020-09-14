#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string);

int main() {

   string filename;
   int sum = 0;

   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;

   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;

   return 0;
}

// Place fileSum implementation here
int fileSum(string fileName){
  ifstream readData;  //declare ifstream to read file data
  int sum = 0;
  int tempData;

  //cout << "Opening file: " << fileName << endl;
  readData.open(fileName);
  if (!readData.is_open()) {
    cout << "Error opening " << fileName << endl;
    exit(1);
  }

  while (!readData.eof()) {
    readData >> tempData;
    if(!readData.fail()) {  //checks if there is an error in the file being read.
      sum = sum + tempData; //In this case, .eof() fails.
    }
  }

  //close reading data file;
  readData.close();
  
  return sum;
}
