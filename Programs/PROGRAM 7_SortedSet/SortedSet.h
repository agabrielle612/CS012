#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

#include "IntList.h"


class SortedSet : public IntList {
    
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();

        bool in(int _data) const;
        SortedSet operator|(const SortedSet &) const;
        SortedSet operator& (const SortedSet &) const;

        void add(int _data);
        void push_front(int);
	    void pop_front();
        void push_back(int);
        void insert_ordered(int);
        SortedSet operator|= (const SortedSet &);
        SortedSet operator&= (const SortedSet &);
};

#endif