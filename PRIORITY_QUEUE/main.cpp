/*
 *  http://library.thinkquest.org/C005618/text/binarytrees.htm
 */
#include <cstdlib>
#include <iostream>

using namespace std;
#define PQ_SIZE 50


typedef struct {
    int q[PQ_SIZE + 1];
    int n;
}priority_queue;



int pq_parent(int n) {
    if(n == 0)
        return -1;
    else
        return ((int) n / 2);
}

int pq_young_child(int n) {
    return (2 * n);
}

void pq_swap(priority_queue *q, int p, int pq_parent(int) ) {
    
}

void bubble_up(priority_queue *q, int p) {
    if(pq_parent(p) == -1) return;
    if(q->q[pq_parent(p)] > q->q[p]) {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}



void pq_insert(priority_queue *q, int x) {
    if(q->n >= PQ_SIZE)
        cout <<"Warning: priority queue overflow insert x= "<<x<<endl;
    else {
        q->n = (q->n) + 1;
        q->q[q->n] = x;
        bubble_up(q, q->n);
    }
}


void pq_init(priority_queue *q){
    q->n = 0;
}


/********************************************/
/*      MAIN PROGRAM                        */
/********************************************/
int main(int argc, char** argv) {


    priority_queue *q;
    int s[PQ_SIZE] = {4, 6, 2, 1, 3, 5};
    pq_init(q);
    
    for (int i = 0; i < PQ_SIZE; i++) {
        pq_insert(q, s[i]);
    }
    

    return 0;
}

