#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList() {
    IntNode *temp = nullptr; //create a temp node to temp point to the address of deletion
    temp = head; //temp now points to the same address as head.
    while (head != nullptr) { //if head is null, do nothing
        head = head -> next;
        delete temp;
        temp = head;
    }
}

void IntList::push_front(int val) {
    IntNode* temp = nullptr;
    temp = head;

    head = new IntNode(val);
    head -> next = temp;

    if (tail == nullptr) {
        tail = head;
    }
   
}

void IntList::pop_front() {
    IntNode* temp = nullptr;
    temp = head;

    if (head == tail) { //head and tail points on the same address
        head = nullptr; //go back to null
        tail = nullptr;
    }
    else if (head != nullptr) {
        head = head -> next;
    }
    
    delete temp;
    
}

bool IntList::empty() const {
    if (head == nullptr && tail == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//Returns a reference to the first value in the list
const int & IntList::front() const {
    return head -> data; //head access the first address of the list, data access the data stored in head which is an int
}

//Returns a reference to the last value in the list.
const int & IntList::back() const {
    return tail -> data;
}

ostream & operator<<(ostream &out, const IntList &val) {
    IntNode *temp = nullptr;
    temp = val.head; 

    while (temp != nullptr) {
        out << temp -> data;
        temp = temp -> next;
        if (temp != nullptr) { //does NOT send a newline or space at the end of the line
            out << " ";
        }
    }

    return out;
}