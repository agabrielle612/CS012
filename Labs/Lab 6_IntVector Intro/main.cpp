#include <iostream>
#include <string>

using namespace std;

#include "IntVector.h"

int main() {
    cout << "Deconstructor Automatically Tested" << endl;

    cout << "Testing Default Constructor..." << endl;
    IntVector t1; 
    
    cout << "Testing IntVector(unsigned, int)" << endl;
    IntVector t2 = IntVector(1, 1);

    cout << "Testing unsigned size() const" << endl;
    cout << "t1 size: " << t1.size() << endl;
    cout << "t2 size: " << t2.size() << endl;

    cout << "Testing unsigned capacity() const" << endl;
    cout << "t1 cap: " << t1.capacity() << endl;
    cout << "t2 cap: " << t2.capacity() << endl;

    cout << "Testing bool empty() const" << endl;
    cout << "t1 should output True and t2 should output False" << endl;
    if (t1.empty()) {
        cout << "t1: True";
    }
    else {
        cout << "t1: False";
    }
    cout << endl;

    if (t2.empty()) {
        cout << "t2: True";
    }
    else {
        cout << "t2: False";
    }
    cout << endl;

    cout << "Testing const int& at(unsigned index) const" << endl;
    IntVector t3 = IntVector(10, 1);
    cout << t3.at(1) << endl;
    //t3.at(10);

    cout << "Testing const int& front() const" << endl;
    IntVector t4 = IntVector(5, 2);
    cout << t4.front() << endl;
    
    cout << "Testing const int& back() const" << endl;
    IntVector t5 = IntVector(6, 3);
    cout << t5.back() << endl;

    return 0;
}
