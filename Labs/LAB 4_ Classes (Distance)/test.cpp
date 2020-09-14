#include <iostream>

using namespace std;

int main(){

    int ft;
    double in;

    cin >> ft >> in;

    int feet = ft;
    double inches = abs(in);

    while (inches >= 12) {
        feet += 1;
        inches -= 12;
    }

    cout << "feet: " << feet << endl;
    cout << "inches: " << inches << endl;

    return 0; 
}