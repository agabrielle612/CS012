//include any standard libraries needed
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
   double avg = 0;

   for (int i = 0; i < arraySize; i++){
      avg = array[i] + avg;
   }

   return avg / static_cast<double> (arraySize);

}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index) {

   for (int i = index; i + 1 < arraySize; i++) {
      array[i] = array[i + 1];
   }
   arraySize -= 1;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
   for (int i = 0; i < arraySize; i++) {
      cout << array[i];
      if (i != arraySize - 1) {
         cout << ", ";
      }
   }
}

const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   string fileName = argv[1];

   // verify file name provided on command line
   if (argc != 2) { 
      cout << "USAGE: " << argv[1] << endl;
      exit(1);
   }

   fstream readFile;

   // open file and verify it opened
   readFile.open(fileName);
   
   if (!readFile.is_open()) {
      cout << "Error opening: " << fileName << endl;
      exit(1);
   }

   // Declare an array of doubles of size ARR_CAP.
   double myArray[ARR_CAP];
   int tempsz = 0;

   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   /*for (int i = 0; i < ARR_CAP; i++) { //if we use ARR_CAP, not right size...
      readFile >> myArray[i]; 
   }*/

   //Based on reading, no error statement when we store on size 0 array...
   while (readFile >> myArray[tempsz]) { //Read arrays like push back
      tempsz++; //but update our size so it corresponds to the size of the data.
   } 

   readFile.close();

   // Call the mean function passing it this array and output the 
   // value returned.
   double _mean = mean(myArray, tempsz); 
   cout << "Mean: " << _mean << endl << endl;

   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int usrIndex;

   cout << "Enter index of value to be removed (0 to " << tempsz - 1 << ") : ";
   cin >> usrIndex;
   cout << endl;

   //usrIndex -= 1; No need to decrease by 1 bc entered from 0 to size - 1
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(myArray, tempsz);
   cout << endl << endl;

   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(myArray, tempsz, usrIndex);

   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(myArray, tempsz);
   cout << endl << endl;
   
   // Call the mean function again to get the new mean
   _mean = mean(myArray, tempsz);
   cout << "Mean: " << _mean << endl;

	return 0;
}