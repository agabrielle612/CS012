#include<iostream>
#include <string>

using namespace std;

int f(const string &s) {
        if (s.size() < 2) {
            return 0;
        }

        if (s.at(0) == s.at(1)) {
            return 1 + f(s.substr(1));
        }

        return f(s.substr(1));
}

int main () {
    // int arr[] = { 11, 3, 5, 8, 10, 4, 2};
    // int *ip = arr + 3; 
    // cout << "answer: " << *ip << ' ' << ip[2] << endl;

    string s = "tweedleddeee";

    cout << s.substr(1) << endl;
    int _f = f(s);

    cout << "f: " << f << endl;
}

//arr = arr[0] == 11
//arr + 3 = arr[3] == 8
//*ip = 8
//ip[2] = ip + 2 == 4