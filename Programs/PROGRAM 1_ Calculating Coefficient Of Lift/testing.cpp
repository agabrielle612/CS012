#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream readData;
    vector<int> v;
    int n;

    readData.open("data_test.dat");

    while (readData >> n) {
        v.push_back(n);
    }

    readData.close();

    int min = v.at(0);
    vector<int> tempv;
    
    //create an algorithm for ascending order set of vectors
    unsigned tempsz = v.size();
    for (unsigned i = 0; i < tempsz; i++) {
        //find first the smallest value
        if (v.at(i) < min) {
            min = v.at(i);
            cout << "min: " << min << endl;
            tempv.push_back(min);
        }
    }

    for (unsigned i = 0; i < v.size(); i++) {
        cout << "v.at(" << i << "): " << v.at(i) << endl;
    }

    for (unsigned i = 0; i < tempv.size(); i++) {
        cout << "tempv.at(" << i << "): " << tempv.at(i) << endl;
    }

    cout << "End of Program.";

    return 0;
} 