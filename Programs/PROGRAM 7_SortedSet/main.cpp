#include <iostream>

using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main() {

    // SortedSet test1;
    // cout << "SortedSet(): " << test1 << endl;
    // test1.push_back(7);
    // test1.push_back(6);
    // test1.push_back(5);

    // cout << "test1: " << test1 << endl;
    
    // cout << "SortedSet Copy Constructor Testing" << endl;
    // SortedSet test2 = test1;
    // cout << "test2: " << test2 << endl;
    // cout << "test2.push_back(4)" << endl;
    // test2.push_back(4);

    // cout << "SortedSet(IntList) Testing" << endl;
    // IntList test3 = test2;
    // test3.push_back(3);
    // cout << "test3: " << test3 << endl;
    
    // cout << endl << "Operator | Testing" << endl;
    // SortedSet test4 = test2 | test3;

    // cout << "test4: " << test4 << endl;
    // test4.push_back(11);

    // cout << endl << "Operator & Testing" << endl;
    // SortedSet test5 = test2 & test4;

    // cout << "test2: " << test2 << endl;
    // cout << "test4: " << test4 << endl;

    // cout << "test5: " << test5 << endl;

    // cout << "Testing In()" << endl;
    // SortedSet test6;

    // cout << "test6: " << endl;
    // test6.in(6);

    // IntList list1;
    // int num = 1;

    // cout << "Enter number: ";
    // while (num != 0) {
    //     cin >> num;
    //     list1.push_back(num);
    // }
    // cout << endl;

    // cout << "list1: " << list1 << endl;

    // list1.insert_ordered(12);
    // cout << "New list1: " << list1 << endl;
    
    SortedSet test7;
    int num = 1;

    cout << "Enter number: ";
    while (num != 0) {
        cin >> num;
        //test7.add(num);
        //test7.push_back(num);
        test7.push_front(num);
        cout << "test7: " << test7 << endl;
    }

    cout << endl;

    cout << "Testing operator |= " << endl;
    SortedSet test8;
    SortedSet test9;

    test9 = test7 |= test8;
    //test9 = test7 & test8;
    test9.push_back(12);
    cout << "test9: " << test9 << endl;     
   

    SortedSet test10;

    // test10 = test8 |= test9;
    // cout << "test10: " << test10 << endl;

    cout << "Testing operator &" << endl;
    test10 = test9 & test8;
    //test10 = test9 & test7;
    cout << "test10: " << test10 << endl;

    

    cout << "End of program." << endl;
    return 0;
}