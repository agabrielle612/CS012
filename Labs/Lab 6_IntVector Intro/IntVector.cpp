#include "IntVector.h"
#include <stdexcept>

using namespace std;

IntVector::IntVector() : sz(0), cap(0), data(nullptr) {}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[sz]; //new dynamically allocates or reserves memory for data from start of address

    //initialize all elements of the array to the value of the 2nd parameter.
    for (unsigned i = 0; i < sz; i++) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete[] data; //[] bc data is an array
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if (sz == 0) {
        return true;
    }

    return false;
}

const int & IntVector::at(unsigned index) const {
    
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

const int & IntVector::front() const {
    return data[0];
}

const int & IntVector::back() const {
    return data[sz - 1];
}