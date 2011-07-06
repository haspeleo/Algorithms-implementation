/* 
 * File:   Stack.cpp
 * Author: doghmen
 * 
 * Created on 31 mars 2011, 16:55
 * http://library.thinkquest.org/C005618/text/binarytrees.htm# --Stack LIFO 
 */

#include <cstdlib>
#include "Stack.h"

#define MAX_SIZE 1000

template <typename ItemType>
Stack<ItemType>::Stack() {
    counter = 0;
    head = NULL;
}

template <typename ItemType>
Stack<ItemType>::Stack(const Stack& orig) {
}

template <typename ItemType>
Stack<ItemType>::~Stack() {
    clear();
    //delete head;
    //counter = 0;
}

template <typename ItemType>
void Stack<ItemType>::push(const ItemType element){
    assert(!isFull()); //abort if not enough memory to create new node

    StackNode<ItemType> s;
    s->data = element;
    s->next =  head;
    head = s;
    counter ++;
}
template <typename ItemType>
ItemType Stack<ItemType>::pop(){
    assert(!isFull());
    ItemType item = head->data;
    StackNode<ItemType> s = head;
    head = head->next;
    delete s;
    counter --;
    return head->data;
}


template <typename ItemType>
ItemType Stack<ItemType>::top() const {
    	assert(!isEmpty());
	return head->data;
}

template <typename ItemType>
void Stack<ItemType>::clear(){
    StackNode<ItemType> *tmp;
    while(head != NULL) {
	tmp = head;
	head = head->next;
	delete tmp;
    }
}
 
template <typename ItemType>
bool Stack<ItemType>::isEmpty() const {
    return (top == NULL);
}

template <typename ItemType>
bool Stack<ItemType>::isFull() const {
	StackNode<ItemType> *tmp = new StackNode<ItemType>;
	if(tmp == NULL)
	    return true;
	else
	    return false;
}

template <typename ItemType>
int Stack<ItemType>::count() const {
	return counter;
 }
