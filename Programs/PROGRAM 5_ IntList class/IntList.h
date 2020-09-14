#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	~IntList();
	void push_front(int);
	void pop_front();
	bool empty() const;
	const int & front() const;
	const int & back() const;

	IntList(const IntList &);
	IntList & operator=(const IntList &);
	void push_back(int);
	void clear();
	void selection_sort();
	void insert_ordered(int);
	void remove_duplicates();
	
	friend ostream & operator<<(ostream &, const IntList &);
};

#endif

