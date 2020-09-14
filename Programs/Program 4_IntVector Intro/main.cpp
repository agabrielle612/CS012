#include <iostream>
#include <string>

using namespace std;

#include "IntVector.h"

int main() {
    // cout << "Deconstructor Automatically Tested" << endl;

    // cout << "Testing Default Constructor..." << endl;
    // IntVector t1; 
    
    // cout << "Testing IntVector(unsigned, int)" << endl;
    // IntVector t2 = IntVector(1, 1);

    // cout << "Testing unsigned size() const" << endl;
    // cout << "t1 size: " << t1.size() << endl;
    // cout << "t2 size: " << t2.size() << endl;

    // cout << "Testing unsigned capacity() const" << endl;
    // cout << "t1 cap: " << t1.capacity() << endl;
    // cout << "t2 cap: " << t2.capacity() << endl;

    // cout << "Testing bool empty() const" << endl;
    // cout << "t1 should output True and t2 should output False" << endl;
    // if (t1.empty()) {
    //     cout << "t1: True";
    // }
    // else {
    //     cout << "t1: False";
    // }
    // cout << endl;

    // if (t2.empty()) {
    //     cout << "t2: True";
    // }
    // else {
    //     cout << "t2: False";
    // }
    // cout << endl;

    // cout << "Testing const int& at(unsigned index) const" << endl;
    // IntVector t3 = IntVector(10, 1);
    // cout << t3.at(1) << endl;
    // //t3.at(10);

    // cout << "Testing const int& front() const" << endl;
    // IntVector t4 = IntVector(5, 2);
    // cout << t4.front() << endl;
    
    // cout << "Testing const int& back() const" << endl;
    // IntVector t5 = IntVector(6, 3);
    // cout << t5.back() << endl;

    // cout <<"Testing insert along with expand()" << endl;
    // IntVector t6 = IntVector(10, 1);
    // cout << "Before insert: " << t6.at(2) << endl;
    // t6.insert(2, 5);
    // cout << "After insert: " << t6.at(2) << endl;
    // // cout << "Check insert_out_of_range error" << endl;
    // // t6.insert(11, 5);
    
    // cout <<"Testing pop_back() && clear()" << endl;
    // IntVector t7 = IntVector(13, 6);
    // cout << "sz before: " << t7.size() << endl;
    // t7.pop_back();
    // cout << "sz after: " << t7.size() << endl;
    // t7.clear();
    // cout << "sz: " << t7.size() << endl;

    // cout <<"Testing resize() && reserve()" << endl;
    // IntVector t8 = IntVector(6, 2);
    // cout << "t8 before: " << t8.size() << " " << t8.back() << endl;
    // t8.resize(8, 9);
    // cout << "t8 after: " << t8.size() << " " << t8.back() << endl;
    // cout << "t8 cap before: " << t8.capacity() << endl;
    // t8.reserve(7);
    // cout << "t8 cap after: " << t8.capacity() << endl;

    // cout << "Testing assign()" << endl;
    // IntVector t9 = IntVector(4, 3);
    // cout << "t9 before: ";
    // for (unsigned i = 0; i < t9.size(); i++) {
    //     cout << t9.at(i) << " ";
    // }
    // cout << endl;
    // t9.assign(7, 7);
    // cout << "t9 after: ";
    // for (unsigned i = 0; i < t9.size(); i++) {
    //     cout << t9.at(i) << " ";
    // }
    // cout << endl;

    // cout << "Testing push_back()" << endl;
    // IntVector t10 = IntVector(10, 2);
    // cout << "Before: ";
    // for (unsigned i = 0; i < t10.size(); i++) {
    //     cout << t10.at(i) << " ";
    // }
    // cout << "Before sz: " << t10.size() << endl;
    // cout << "After: ";
    // t10.push_back(7);
    //  for (unsigned i = 0; i < t10.size(); i++) {
    //     cout << t10.at(i) << " ";
    // }
    // cout << "Update sz: " << t10.size() << endl;

    // cout << "Testing erase()" << endl;
    // cout << "Before: ";
    //  for (unsigned i = 0; i < t10.size(); i++) {
    //     cout << t10.at(i) << " ";
    // }
    // cout << "Before sz: " << t10.size() << endl;
    // t10.erase(10);
    // cout << "After: ";
    // for (unsigned i = 0; i < t10.size(); i++) {
    //     cout << t10.at(i) << " ";
    // }
    // cout << "Update sz: " << t10.size() << endl;

    // cout << "Testing resize function: " << endl;
    // IntVector t11 = IntVector(5, 2);
    // cout << "Before sz: " << t11.size() << " Before cap: " << t11.capacity() << endl;
    // for (unsigned i = 0; i < t11.size(); i++) {
    //     cout  << "t11.at(" << i << "): " << t11.at(i) << endl;
    // }
    // cout << endl;
    // t11.resize(10, 8);
    // cout << "After sz: " << t11.size() << " After cap: " << t11.capacity() << endl;
    // for (unsigned i = 0; i < t11.size(); i++) {
    //     cout  << "t11.at(" << i << ")" << t11.at(i) << endl;
    // }
    // cout << endl;

    // cout << "Testing push_back()" << endl;
    // IntVector t12(7, 6);
    // cout << "Before sz: " << t12.size() << " Before cap: " << t12.capacity() << endl;
    // for (unsigned i = 0; i < t12.size(); i++) {
    //     cout  << "t12.at(" << i << "): " << t12.at(i) << endl;
    // }
    // t12.push_back(8);
    // cout << "After sz: " << t12.size() << " After cap: " << t12.capacity() << endl;
    // for (unsigned i = 0; i < t12.size(); i++) {
    //     cout  << "t12.at(" << i << "): " << t12.at(i) << endl;
    // }

    // IntVector t13;
    // cout << "Before sz: " << t13.size() << " Before cap: " << t13.capacity() << endl;
    // for (unsigned i = 0; i < t13.size(); i++) {
    //     cout  << "t13.at(" << i << "): " << t13.at(i) << endl;
    // }
    // t13.push_back(200);
    // cout << "After sz: " << t13.size() << " After cap: " << t13.capacity() << endl;
    // for (unsigned i = 0; i < t13.size(); i++) {
    //     cout  << "t13.at(" << i << "): " << t13.at(i) << endl;
    // }
    // cout << endl;

    // cout << "Testing assign()" << endl;
    // IntVector t14(40, 5);
    // IntVector t15;

    // cout << "Before sz: " << t14.size() << " Before cap: " << t14.capacity() << endl << endl;
    // t14.assign(100, 5);
    // cout << "After sz: " << t14.size() << " After cap: " << t14.capacity() << endl << endl;

    // cout << "Test 15" << endl;
    // cout << "Before sz: " << t15.size() << " Before cap: " << t15.capacity() << endl << endl; 
    // t15.assign(20, 5);
    // cout << "After sz: " << t15.size() << " After cap: " << t15.capacity() << endl << endl;

    cout << "Testing insert()" << endl;
    IntVector t16( 5, 10);

    cout << "Before sz: " << t16.size() << " Before cap: " << t16.capacity() << endl << endl;
    for (unsigned i = 0; i < t16.size(); i++) {
    cout  << "t16.at(" << i << "): " << t16.at(i) << endl;
    }

    //t16.insert(7, 4);

    t16.insert(1, 4);
    cout << "Insert position" << endl << endl;

    for (unsigned i = 0; i < t16.size(); i++) {
    cout  << "t16.at(" << i << "): " << t16.at(i) << endl;
    }
    cout << "After sz: " << t16.size() << " After cap: " << t16.capacity() << endl << endl;

    
    return 0;
}
