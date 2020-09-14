#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string, char);

int main() {
   string filename;
   char ch;
   int chCnt = 0;

   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);
   cout << "# of " << ch << "'s: " << chCnt << endl;

   return 0;
}

// Place charCnt implementation here
int charCnt(string fileName, char ch) {
  ifstream readData;
  int chCount = 0;
  char tempCh;
  //cout << "Opening file: " << fileName << endl;
  readData.open(fileName);
  if (!readData.is_open()) {
    cout << "Error opening " << fileName << endl;
    exit(0);
  }

  while (readData.get(tempCh)) { //get also takes whitespace and newline
    if (ch == tempCh) {
      ++chCount;
    }
  }

  //cout << "Closing file: " << fileName << endl;
  readData.close();

  return chCount;
}
