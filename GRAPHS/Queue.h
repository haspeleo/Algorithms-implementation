/* 
 * File:   Queue.h
 * Author: doghmen
 *
 * Created on 30 mars 2011, 23:53
 */

#ifndef QUEUE_H
#define	QUEUE_H


struct node {
    int info;
    node *next;

};

class Queue {

public:
    Queue();
    ~Queue();
    //Queue(const Queue& orig);
    //virtual ~Queue();
    bool isEmpty();
    void add(int);
    int get();

private:
    node *first, *last;

};



#endif	/* QUEUE_H */

