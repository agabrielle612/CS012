#include <iostream>
#include <algorithm>
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

//must initialize head and tail to nullptr bc CREATING A NEW node.
IntList::IntList(const IntList &cpy) : head(nullptr), tail(nullptr) {
    
    if (!head) {
        clear();
    }
    
    for (IntNode* curr = cpy.head; curr != nullptr; curr = curr -> next) {
        push_back(curr -> data);
    }

}

//similar to copy constructor only called when node is ALREADY declared.
IntList& IntList::operator=(const IntList &rhs) {

    if (this != &rhs) {
        
        if (!head) {
            clear();
        }

        head = nullptr;
        tail = nullptr;

        for (IntNode* curr = rhs.head; curr != nullptr; curr = curr -> next) {
        push_back(curr -> data);
        } 
    }
    
    return *this;
}
void IntList::push_back(int value) {
    
    if (head == nullptr) {
        tail = new IntNode(value); //list empty so set val to head and point it also to tail
        head = tail;
    }
    else {
        tail -> next = new IntNode(value);  //create and allocate value to the tail pointing to next;
        tail = tail -> next;
    }
}

void IntList::clear() {
    
    if (head != nullptr) {
        IntNode* temp = head;
        while (head != nullptr) {
            head = head -> next;
            delete temp;
            temp = head;
        }
    }

    head = nullptr;
    tail = nullptr;
}
/*

1. create curr var
2. create min var
3. compare curr to rest of data.
4. if data is less than i0
5. swap min and curr
6. update i
*/
void IntList::selection_sort() {
    //based from Selection Sort in Zybooks
    //instead of index, use pointers
    for (IntNode* curr = head; curr != nullptr; curr = curr -> next) {
        IntNode* min = curr;
        for (IntNode* i = curr->next; i != nullptr; i = i -> next) {
            if ( i -> data < min -> data ){
                min = i;
            }
        }
        swap ((curr -> data) , (min -> data));
    }
}
/*
1. Assummed that list is ALREADY sorted
2. make 2 ptrs, prev & curr
3. allocate a new intnode(x) with value
4. check if (x <= curr), insert
5. else, update prev and curr
6. special case 1, if (empty()), call push_front
7. special case 2, if (x <= head), call push_front
8. special case 3, if (x >= tail), call push_back
*/
void IntList::insert_ordered(int value) {
    
    IntNode* insrtval = new IntNode(value);

    if (empty() || ( insrtval -> data <= head -> data )) {
        push_front(value);
    }
    else if (insrtval -> data >= tail -> data) {
        push_back(value);
    }
    else {
        IntNode* prev = head;
        IntNode* curr = head -> next;

        while (curr != nullptr) {
            if (insrtval -> data <= curr -> data) {
                insrtval -> next = curr;
                prev -> next = insrtval;
                break;
            }
            else {
                prev = curr;
                curr = curr -> next;
            }
        }
    }
}
/*
Removes all duplicate data values (actually removes the nodes that contain the values) within the list.
Always remove just the later value within the list when a duplicate is found. 
This function may NOT ever sort the list.
*/
void IntList::remove_duplicates() {
    
    if (head == nullptr || head == tail) {
        return;
    }
    else {
        for (IntNode* i = head; i != nullptr; i = i -> next) {
            IntNode* prev = i;
            while (prev -> next != nullptr) {
                IntNode* j = prev -> next;
                    if (i -> data == j -> data) {                  
                    prev -> next = j -> next;
                    delete j;
                    j = prev -> next;
                    if (j == nullptr) {
                        tail = prev;
                    }
                }
                else { 
                    prev = prev -> next;
                }
            } 
            
        }
    }
    
}