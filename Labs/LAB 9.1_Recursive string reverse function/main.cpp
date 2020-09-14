#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here

void flipString(string &s) {
   
   if (s.size() <= 1) { 
      return;
   }
   else if (s.size() == 2) {
      swap(s.front(), s.back());
      return;
   }
   else {
      swap(s.front(), s.back());
      string temp = s.substr(1, s.size() - 2);
      //cout << endl << "temp: " << temp << endl << endl;
      flipString(temp);
      s =  s.front() + temp + s.back();  
   } 

   //cout << "STRING: " << s << endl;
   
}

