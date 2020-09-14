#include <iostream>
#include <fstream>

using namespace std;

void display(const int arr[], int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

void adjust(int arr[], int size, int adjustment) {
    for (int i = 0; i < size; i++) {
        arr[i] += adjustment;
    }
}

int main(int argc, char *argv[]) {
    const int ARR_CAP = 1000;

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " data_file" << endl;
        return 1;
    }

    ifstream fin;
    fin.open(argv[1]);
    if (!fin) {
        cout << "Error opening: " << argv[1] << endl;
        return 1;
    }

    int scores[ARR_CAP];
    int arrSize = 0;

    while (arrSize < ARR_CAP && fin >> scores[arrSize]) {
        ++arrSize;
    }

    display(scores, arrSize);
    cout << endl;

    adjust(scores, arrSize, 2);

    display(scores, arrSize);
    cout << endl;

    return 0;
}