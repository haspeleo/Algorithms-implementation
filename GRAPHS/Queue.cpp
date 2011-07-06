/* 
 * File:   Queue.cpp
 * Author: doghmen
 * 
 * Created on 30 mars 2011, 23:53
 * http://xoax.net/comp/cpp/console/index.php //C++ tutorials
 */

#include "Queue.h"
#include <cstdlib>

//Queue::Queue() {
//}
//
//Queue::Queue(const Queue& orig) {
//}
//
//Queue::~Queue() {
//}


Queue::Queue() {
    first = new node;
    first->next = NULL;
    last = first;
}

Queue::~Queue() {
    delete first;
}

bool Queue::isEmpty() {
    return (first->next == NULL);
}

void Queue::add(int x) {
    node *aux = new node;
    aux->info = x;
    aux->next = NULL;
    last->next = aux;
    last = aux;
}

int Queue::get() {
    node *aux = first->next;
    int value = aux->info;
    first->next = aux->next;
    if (last == aux) last = first;
    delete aux;
    return value;
}
