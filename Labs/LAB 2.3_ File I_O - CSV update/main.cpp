#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
    string inputFile;
    string outputFile;
   
    if (argc != 3) {
        cout << "Error!" << endl;
        return 1;
    }
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
    inputFile = argv[1];
    outputFile = argv[2];
   
   // Create input stream and open input csv file.
    ifstream readData;
    readData.open(inputFile);
    
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!readData.is_open()) {
       cout << "Error Opening " << inputFile << endl;
       return 1;
   }
   // Read in integers from input file to vector.
    vector<int> data;
    int valTemp;
    char temp; //for comma;
    
    while(!readData.eof()) {//gets data until the end of file data.
       readData >> valTemp;
       if (!readData.fail()) {
           data.push_back(valTemp);
       }
        readData.clear(); //reset the state of the stream 
        readData >> temp; //so next extraction is an input char
   }
   // Close input stream.
   readData.close();
       
   // Get integer average of all values read in.
    int avg = 0;
    for (unsigned i = 0; i < data.size(); i++) {
        avg = avg + data.at(i);
    }
    
    avg = avg / data.size();
   // Convert each value within vector to be the difference between the original value and the average.
    for (unsigned i = 0; i < data.size(); i++) {
        data.at(i) = data.at(i) - avg; 
    }
    
   // Create output stream and open/create output csv file.
    ofstream outData;
    outData.open(outputFile);
    
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outData.is_open()) {
       cout << "Error opening" << endl;
       return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
    for (unsigned i = 0; i < data.size(); i++) {
        outData << data.at(i);
        if (i != data.size() - 1) {
            outData << ',';
        }
    }
   // Close output stream.
   outData.close();
    
   return 0;
}