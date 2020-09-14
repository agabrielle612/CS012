#include <iostream>

using namespace std;

int getInt(string prompt) {
    int n;
    cout << prompt;
    cin >> n;
    cout << endl;

    while (cin.fail()) {
        cin.clear(); //reset error state
        cin.ignore(256, '\n'); //empties the buffer
        cout << "Error: please re-enter: " << endl;
        cout << prompt;
        cin >> n;
        cout << endl;
    }

    return n;
}

int main() {
    int score1 = 0;
    int score2 = 0;

    score1 = getInt("Enter first score: ");
    score2 = getInt("Enter secod score: ");

    cout << "score1: " << score1 << endl;
    cout << "score2: " << score2 << endl;

}