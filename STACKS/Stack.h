/* 
 * File:   Stack.h
 * Author: doghmen
 *
 * Created on 31 mars 2011, 16:55
 * http://www.boost.org/doc/libs/1_35_0/libs/graph/doc/table_of_contents.html --boost
 * aptitude install libboost-graph-dev --to install boost library
 * cours avancé C++
 * http://www.nawouak.net/?doc=course.cpp+lang=fr
 *
 * Le But des template est de se dire "je ne sais pas ce que je manipule,
 * mais je sais comment je le manipule"
 * http://www.cplusplus.happycodings.com/Data_Structures/code12.html //interactive stack
 */

#ifndef STACK_H
#define	STACK_H

template <typename ItemType = int>
struct StackNode {
    ItemType data;
    StackNode<ItemType> *next;
};

template <typename ItemType = int>
class Stack {

public:
    Stack();
    Stack(const Stack& orig);
    virtual ~Stack();
    void push(const ItemType);
    ItemType pop();
    ItemType top() const;
    void clear();
    bool isEmpty() const;
    bool isFull() const;
    int count() const;

private:

    StackNode<ItemType> *head;
    int counter;
};

#endif	/* STACK_H */

