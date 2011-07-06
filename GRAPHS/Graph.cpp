/* 
 * File:   Graph.cpp
 * Author: doghmen
 *
 * http://www.codersource.net/c/c-miscellaneous/breadth-first-search-in-c.aspx
 * Created on 30 mars 2011, 23:45
 */


#include "Graph.h"
#include "Queue.h"
#include <iostream>
using namespace std;

//Graph::Graph() {
//}
//
//Graph::Graph(const Graph& orig) {
//}
//
//Graph::~Graph() {
//}

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}


Graph::~Graph() {
    for (int i = 0; i < n; ++i)
        delete [] A[i];
    delete [] A;
}


bool Graph::isConnected(int x, int y) {
    return (A[x - 1][y - 1] == 1);
}

void Graph::addEdge(int x, int y) {
    A[x - 1][y - 1] = A[y - 1][x - 1] = 1;
}

void Graph::BFS(int x) {
    Queue Q;
    bool *visited = new bool[n + 1];
    int i;
    for (i = 1; i <= n; ++i)
        visited[i] = false;
    Q.add(x);
    visited[x] = true;
    cout << "Breadth First Search starting from vertex ";
    cout << x << " : " << endl;
    while (!Q.isEmpty()) {
        int k = Q.get();
        cout << k << " ";
        for (i = 1; i <= n; ++i)
            if (isConnected(k, i) && !visited[i]) {
                Q.add(i);
                visited[i] = true;
            }
    }
    cout << endl;
    delete [] visited;
}

void Graph::minPath(int start, int target) {
    Queue Q;
    int i, p, q;
    bool found;

    struct aux {
        int current, prev;
    };
    aux *X = new aux[n + 1];
    int *Y = new int[n + 1];
    bool *visited = new bool[n + 1];
    for (i = 1; i <= n; ++i)
        visited[i] = false;
    Q.add(start);
    visited[start] = true;
    found = false;
    p = q = 0;
    X[0].current = start;
    X[0].prev = 0;
    while (!Q.isEmpty() && !found) {
        int k = Q.get();
        for (i = 1; i <= n && !found; ++i)
            if (isConnected(k, i) && !visited[i]) {
                Q.add(i);
                ++q;
                X[q].current = i;
                X[q].prev = p;
                visited[i] = true;
                if (i == target) found = true;
            }
        ++p;
    }
    cout << "The minimum length path from " << start;
    cout << " to " << target << " is : " << endl;
    p = 0;
    while (q) {
        Y[p] = X[q].current;
        q = X[q].prev;
        ++p;
    }
    Y[p] = X[0].current;
    for (q = 0; q <= p / 2; ++q) {
        int temp = Y[q];
        Y[q] = Y[p - q];
        Y[p - q] = temp;
    }
    for (q = 0; q <= p; ++q)
        cout << Y[q] << " ";
    cout << endl;
    cout << "Length = " << q - 1 << endl;
    delete [] visited;
    delete [] X;
    delete [] Y;
}
