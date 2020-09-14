#include <iostream>
#include "minFunc.h"

using namespace std;

const int * min(const int arr[], int arrSize) {

    if (arrSize <= 0) {
        return &arr[0];
    }
    else if (arrSize == 1) {
        return &arr[0];
    }
    else if (arrSize == 2) {
        if ( arr[0] > arr[1]) {
            return &arr[1];
        }
        else {
            return &arr[0];
        }
    }
    else {
        if (arr[0] > arr[arrSize - 1]) {
            return (min(arr + 1, arrSize));
        }
    }
    return (min(arr, arrSize - 1));

}