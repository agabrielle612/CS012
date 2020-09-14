#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main( int argc, char* argv[]){

    //check command line argument
    if (argc != 2) {
        cout << "Usage: program1.exe error." << endl;
        return 1;
    }

    string windTunnelData = argv[1]; //read filename in command line.
    //cout << "Successful command line: " << windTunnelData << endl;

    vector<double> flightAngle, coefficient;
    readData(windTunnelData, flightAngle, coefficient);

    //check if flight-path angles are in order
    //cout << "Checking if " << windTunnelData << " is ordered..." << endl;
    bool smlToLrg = isOrdered(flightAngle);

    if (!smlToLrg) {
        //cout << "Ordering..." << endl;
        reorder(flightAngle,coefficient);
        cout << "Data is now ordered!" << endl;
    }

    //ask user for a flight=path angle
    string enterAnotherAngle = "Yes";
    double usrFlAngle;

    while (enterAnotherAngle != "No") {
        cout << "Enter a flight-path angle: ";
        cin >> usrFlAngle;

        /*If the angle is within the bounds of the data set, 
        the program should then use linear interpolation*/
        double usrCff = 0;
        if (usrFlAngle >= flightAngle.at(0) && usrFlAngle <= flightAngle.back()) {
            usrCff = interpolation(usrFlAngle, flightAngle, coefficient);
            cout << "User coefficient: " << usrCff << endl;

            
        }
        else {
            cout << "Flight Angle: " << usrFlAngle << " not within data. Program exited." << endl;
            return 1;
        }

        //Ask user to enter another flightAngle.
        cout << "Do you want to enter another flight path-angle? ";
        cin >> enterAnotherAngle;
    }

    cout << "End of Program!" << endl;
    return 0;

}
//Helper Functions
void readData(const string & wndTunData, vector<double> &flAngle, vector<double> &cff) {
    
    ifstream scanData;

    //cout << "Opening " << wndTunData << endl;
    scanData.open(wndTunData);

    if (!scanData.is_open()) {
        cout << "Error opening " << wndTunData << endl;
        exit(1);
    }

    double tempFlAngle, tempCff; 
    
    while (scanData >> tempFlAngle >> tempCff) {
        flAngle.push_back(tempFlAngle);
        cff.push_back(tempCff);
    }

    //cout << "Closing " << wndTunData << endl;

    scanData.close();
}

double interpolation(double usrFlAngle, const vector<double> &flAngle, const vector<double> &cff) {
    
    //Based on user flight-path angle, find corresponding coefficient
    //Checking if entered angle is within data. 
    for (unsigned i = 0; i < flAngle.size(); i++) {
        //if usrFlAngle's cff is within data
        if (flAngle.at(i) == usrFlAngle) { 
            return cff.at(i);
        }
    }
    
    cout << "User flight-angle not in given data. Proceeding to calculate interpolation..." << endl;
    double a, c, fa, fc;
    unsigned indexUsrCff = 0;
    
    //find the low boundary
     for (unsigned i =0; i < flAngle.size(); i++) {
        if (flAngle.at(i) < usrFlAngle) {
            a = flAngle.at(i);
            fa = cff.at(i);
            indexUsrCff = i; 
        }
     }
     cout << "a: " << a << " fa: " << fa << endl;
    
    //find the high boundary
    c = flAngle.at(indexUsrCff + 1); //next index because of boundary
    fc = cff.at(indexUsrCff + 1);

    cout << "c: " << c << " fc: " << fc << endl;

    //calculate for f(b);
    double usrInterpolation = 0;
    usrInterpolation = fa + ((usrFlAngle - a) / (c - a)) * (fc - fa);

    return usrInterpolation;
}

bool isOrdered(const vector<double> &flAngle) {    
    
    for (unsigned i = 0; i < flAngle.size() ; ++i) {
        if (flAngle.at(i) > flAngle.back() || flAngle.at(i) < flAngle.at(0)) { 
            return false;
        }
    }

    //vector<double> temp = flAngle;
    //temp.push_back(100.0); //create a dummy vector and add another dummy number so no need to decrease size.

    //flAngle.size() - 1 not ideal bc it returs an unsigned 0 - 1
    //This is why it does not work for empty vectors
    
    for (unsigned i = 0; i + 1 < flAngle.size(); ++i) {
        //cout << flAngle.at(i) << " > " << flAngle.at(i+1) << endl;
        if (flAngle.at(i) > flAngle.at(i + 1)) {
            return false;
        }
    }

    return true;
}
void reorder(vector<double> &flAngle, vector<double> &cff) {
    unsigned indexSmallest = 0;
    
    for (unsigned i = 0; i < flAngle.size(); i++) {
        indexSmallest = i; 
        
        for (unsigned j = i + 1; j < flAngle.size(); j++) {
            if (flAngle.at(j) < flAngle.at(indexSmallest))
                indexSmallest = j;
        }

        swap(flAngle.at(i), flAngle.at(indexSmallest));
        swap(cff.at(i), cff.at(indexSmallest));

    }
}