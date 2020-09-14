#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

    IntList list1;

    cout << "popfront null" << endl;
    list1.pop_front();

    cout << list1 << endl;


    cout << "pushfront 10" << endl;
    list1.push_front(10);
    cout << list1 << endl;
    
    cout << "popfront 10" << endl;
    list1.pop_front();
    cout << "list1: " << list1 << endl;

    bool n = list1.empty();
    if (n) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    

    return 0;
}