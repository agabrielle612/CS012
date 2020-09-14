#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &_cpy) : IntList(_cpy) {}

SortedSet::SortedSet(const IntList &_cpy) : IntList(_cpy) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int _data) const {
    
    IntNode* curr = this-> head;

    while (curr != nullptr) {
        if (curr -> data == _data) {
            return true;
        }
        curr = curr -> next;
    }
    
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &_rhs) const {
    
    SortedSet set;

    //cout << "rhs: " << rhs << endl;
    for (IntNode* curr = head; curr != nullptr; curr = curr -> next) {
        set.push_back(curr->data);
    }

    for (IntNode* curr = _rhs.head; curr != nullptr; curr = curr-> next) {
        set.push_back(curr->data);
    }
    
    //set.remove_duplicates();

    return set;
}

SortedSet SortedSet::operator& (const SortedSet &_rhs) const {
    
    SortedSet set;

    if (this == &_rhs) {
        return *this;
    }
    
    IntNode* temp = this-> head;

    for (IntNode* curr = _rhs.head; curr!= nullptr; curr = curr -> next) {
        if (temp == nullptr) {
            break;
        }
        if (temp -> data == curr -> data) {
            set.push_back(curr-> data);
        }
        temp = temp -> next;
    }

    return set;
}

void SortedSet::add(int _data) {
    
    if (in(_data)) {
        return;
    }
    else {
        IntList::insert_ordered(_data);
    }

}

void SortedSet::push_front(int _data) {
    add(_data);
}

void SortedSet::push_back(int _data) {
    add(_data);
}

void SortedSet::insert_ordered(int _data) {
    add(_data);
}

SortedSet SortedSet::operator|= (const SortedSet &rhs) {

    //cout << "rhs: " << rhs << endl;

    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr-> next) {
        push_back(curr->data);
    }

    selection_sort();
    remove_duplicates();

    return *this;
}

SortedSet SortedSet::operator&= (const SortedSet &rhs) {
    
    if (this == &rhs) {
        return *this;
    }

    IntNode* temp = this-> head;
    this-> head = new IntNode(0);
    head = nullptr;
    tail = nullptr;

    for (IntNode* curr = rhs.head; curr!= nullptr; curr = curr -> next) {
        if (temp == nullptr) {
            break;
        }
        if (temp -> data == curr -> data) {
            push_back(curr-> data);
        }
        temp = temp -> next;
    }

    return *this;
}

