/* 
 * File:   Graph.h
 * Author: doghmen
 *
 * Created on 30 mars 2011, 23:45
 */

#ifndef GRAPH_H
#define	GRAPH_H

class Graph {

public:
    Graph(int size = 2);
    ~Graph();
    //virtual ~Graph();
    //Graph(const Graph& orig);

    bool isConnected(int, int);
    // adds the (x, y) pair to the edge set
    void addEdge(int x, int y);
    // performs a Breadth First Search starting with node x
    void BFS(int x);
    // searches for the minimum length path
    // between the start and target vertices
    void minPath(int start, int target);
private:
    int n;
    int **A;
};


#endif	/* GRAPH_H */

