#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char*argv[]){
        
    if (argc < 2) {
        cout << "USAGE: " << argv[0] << " input_file" << endl;
    }
        
    ifstream fin(argv[1]); 
    
    if (!fin.is_open()) {
        cout << "Error opening " << argv[1] << endl;
        return 1;
    }

    int numLines = 0;
    int numWords = 0;
    int numChars = 0;

    istringstream ssin; //use to parse into words

    //.str() = initialize the stream's buffer to string lineString

    string line, word;
    while (getline(fin, line)) {
        ++numLines;
        ssin.str(line); //take all contents of line to ssin;
        while (ssin >> word) {
            ++numWords;
        }
        ssin.clear(); //when a bitfails bc of the while, it resets the bitfail and therefore continue to storing
                      //storing into the variable.
        numChars += line.size() + 1; //add 1 because getline ignore newline. Does not store it into the string.
    }


    return 0;
}