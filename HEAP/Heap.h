/* 
 * File:   Heap.h
 * Author: doghmen
 * Created on 8 avril 2011, 17:47
 *
 * http://www.algolist.net/Data_structures/Binary_heap/Array-based_int_repr
 */

#ifndef HEAP_H
#define	HEAP_H

const int MAX_SIZE = 100;

template<typename ItemType>
class Heap {
public:
    Heap();
    virtual ~Heap();
    int left(int) const;
    int right(int) const;
    int parent(int) const;
    void insert(const ItemType&);
    ItemType removeMax();
    bool isEmpty() const;
    bool isFull() const;
    int count() const;
private:
    ItemType array[MAX_SIZE];
    int nbElements;
    void reHeap(int);
};

#endif	/* HEAP_H */

