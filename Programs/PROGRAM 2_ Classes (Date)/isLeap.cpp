#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned y;
    string isLeap;

    cout << "Enter y: " << endl;
    cin >> y;

   if (y % 4 == 0) {
      if (y % 100 == 0) {
         isLeap = "false";
      }
      if (y % 400 == 0) {
        isLeap = "true";
      }
      isLeap = "true";
   }
   else {
       isLeap = "false";
   }
   cout << isLeap << endl;
   return 0;
}
