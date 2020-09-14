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

void IntVector::expand() {
    //cout << "Called: expand()" << endl;
    
    cap = 2 * cap;

    if (cap == 0) {
        cap = 1;
    }

    int* prev = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        prev[i] = data[i];
    }

    data = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        data[i] = prev[i];
    }

    delete[] prev;
}

void IntVector::expand(unsigned amount) {
    //cout << "Called: expand(unsigned)" << endl;

    cap += amount;

    int* prev = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        prev[i] = data[i];
    }

    data = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        data[i] = prev[i];
    }
    delete[] prev;
}

void IntVector::insert(unsigned index, int value) {
    
    if (index > sz) {
        throw out_of_range("IntVector::insert_range_check");
    } 

    if (sz >= cap) {
        expand();
    }

    //This function inserts data at position index. To do this, 
    //all values currently at position index and greater are shifted 
    //to the right by 1 (to the element right after its current position).
    sz += 1;

    for (unsigned i = index; i + 1 < sz; i++) {
        data[i + 1] = data[i];
    }   
    
    data[index] = value;
}

void IntVector::erase(unsigned index) {
    
    if (index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i + 1 < sz; i++) {
        data[i] = data[i + 1];
    }
    
    sz -= 1;
}

void IntVector::push_back(int value) {
    
    if (sz >= cap) {
        expand();
    }

    sz += 1;
    data[sz - 1] = value;
}

void IntVector::pop_back() {
    sz -= 1;
}

void IntVector::clear() {
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {

    if (size > (2 * cap)) { // based on  expand();
        expand(size - cap);
    }
    else if (size > cap) {
        expand();
    }
    
    //If size is smaller than the current size(sz), 
    //this function just reduces the value of sz to size.
    if (size < sz) {
        sz = size;
        return;
    }

    //If size is greater than the current size(sz), 
    //then the appropriate number of elements are 
    //inserted at the end of the vector, giving all 
    //of the new elements the value passed 
    //in through the 2nd parameter (value).
    else {

        int* tempdata = new int[cap];
        for (unsigned i = 0; i < sz; i++) {
            tempdata[i] = data[i];
        }

        data = new int[cap];
        for (unsigned i = 0; i < sz; i++) {
            data[i] = tempdata[i];
        }
        for (unsigned i = sz; i < size; i++) {
            data[i] = value;
        }

        sz = size;
        delete [] tempdata;
    }

    //*not necessarily more memory but more allocations;
}

void IntVector::reserve(unsigned n) {
    if (n > cap) {
        cap = n;
    }
}

void IntVector::assign(unsigned n, int value) {
    

    if (n > (2* cap)) {
        expand(n - cap);
    }
    else if (n > cap) {
        expand();
    }

    sz = n;
    data = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        data[i] = value;
    }
}

int & IntVector::at(unsigned index) {
    
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

int & IntVector::front() {
    return data[0];
}

int & IntVector::back() {
    return data[sz - 1];
}
