/* 
 * File:   Heap.cpp
 * Author: doghmen
 * 
 * Created on 8 avril 2011, 17:47
 * http://www.boost.org/community/error_handling.html --exception handling
 * http://www.boost.org/doc/libs/1_46_1/more/getting_started/unix-variants.html --boost library tutorial
 */
#include <cstdlib>
#include <exception>

#include "Heap.h"
template<typename ItemType>
Heap<ItemType>::Heap() {
    nbElements = 0;
}

template<typename ItemType>
Heap<ItemType>::~Heap() {
    delete [] array;
}
template<typename ItemType>
int Heap<ItemType>::left(int nodeIndex) const {
    return (2 * nodeIndex + 1);
}
template<typename ItemType>
int Heap<ItemType>::right(int nodeIndex) const {
   int index = nbElements - 1 / 2;
   if(nodeIndex < index)
	   throw  std::exception("no right leaf for this node! ");
   else

           return (2 * nodeIndex + 2);
}

template<typename ItemType>
int Heap<ItemType>::parent(int nodeIndex) const {
    return (nodeIndex - 1) / 2;
}

template<typename ItemType>
void Heap<ItemType>::insert(const ItemType& item) {
    if (!isFull())
        throw std::exception("Heap is Full!");
    else {
        array[nbElements] = item;
        int new_pos = nbElements;
        nbElements++;
        while ((new_pos != 0) && (array[new_pos] > array[parent(new_pos)])) {
            swap(array[new_pos], array[parent(new_pos)]);
            new_pos = parent(new_pos);
        }
    }
}

template<typename ItemType>
ItemType Heap<ItemType>::removeMax() {
    if(isEmpty())
	throw std::exception("Heap is empty!");
    else {
	nbElements --;

	if(nbElements != 0) {
	    swap(array[0], array[nbElements]);
	    reHeap(0);
	}
    }
}

template<typename ItemType>
void Heap<ItemType>::reHeap(int item) {

}

template<typename ItemType>
bool Heap<ItemType>::isEmpty() const {
	return (nbElements == 0);
}

template<typename ItemType>
bool Heap<ItemType>::isFull() const {
   return (nbElements == MAX_SIZE);
}

template<typename ItemType>
int Heap<ItemType>::count() const {
	return nbElements;
}

