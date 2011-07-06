/* 
 * File:   Graph.cpp
 * Author: doghmen
 * 
 * Created on April 15, 2011, 3:30 PM
 */

#include <queue>
#include <set>

#include "Graph.h"


Graph::Graph() {}

Graph::Graph(const Graph& orig) {}

Graph::~Graph() {}

//void Graph::DepthFirstSearch(nodeT* curr, set<nodeT*>& visited) {
//    
//    if(visited.contains(curr)) return;
//    //do something with curr
//    visited.add(curr);
//    
//    for (int i = 0; i < curr->outgoing.size(); i++) {
//        DepthFirstSearch(curr->outgoing[i]->end, visited)
//    }
//}
//void Graph::BreadthFirstSearch(nodeT* start) {
//    
//    queue<nodeT*> q;
//    set<nodeT*> visited;
//    q.enqueue(start);
//    
//    while(!q.empty()) {
//        nodeT *curr = q.dequeue();
//        if(!visited.contains(curr)) {
//            visited.add(curr);
//            
//            for(int i = 0; i < curr->outgoing.size(); i++) {
//                q.enqueue(curr->outgoing[i]->end);
//            }
//        }
//    }
//    
//}