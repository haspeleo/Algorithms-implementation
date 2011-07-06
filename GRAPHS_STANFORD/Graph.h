/* 
 * File:   Graph.h
 * Author: doghmen
 *
 * Created on April 15, 2011, 11:39 AM
 * http://www.youtube.com/watch?v=DLRBkVADdU0  --lecture 23 programming abstractions
 * http://www.java2s.com/Tutorial/Cpp/0380__set-multiset/Declareastringset.htm
 * for set class:
 * http://www.commentcamarche.net/faq/11255-introduction-a-la-stl-en-c-standard-template-library#std-set-t
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <vector>
#include <string>
#include <set>

using namespace std;


//////////////////////////////
/*  Data stucture for graphs */
//////////////////////////////

struct nodeT; //for resolving circular reference

struct arcT {
    //arc fields
    double cost;
    double distance;
    
    nodeT *start;
    nodeT *end;
};

struct NodeT {
    //node fields
   std::string name;
   vector<arcT *> outgoing;
};

class Graph {

public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    void DepthFirstSearch(nodeT * curr, set<nodeT*> &visited);
    void BreadthFirstSearch(nodeT *start);

private:

};

#endif	/* GRAPH_H */

