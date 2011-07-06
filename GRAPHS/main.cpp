/* The Algorithm design manual p.153
 *
 * http://www.cppreference.com/wiki/algorithm/start --algorithms defined in <algorithm>
 */

#include "Graph.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

    Graph g(5);
    
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(2, 5);

    g.BFS(1);
    g.minPath(1, 5);
    return 0;
}



//#include <cstdlib>
//#include <iostream>
//
//#define MAXV 1000
//
//using namespace std;
//
//struct edgenode {
//    int y;
//    int weight;
//    struct edgenode *next;
//};
//
//struct graph {
//  edgenode *edges[MAXV + 1];
//  int degree[MAXV + 1];
//  int nvertices;
//  int nedges;
//  bool directed;
//};
//
//void initializeGraph(graph *g, bool directed) {
//    g->nvertices = 0;
//    g->nedges = 0;
//    g->directed = directed;
//
//    for(int i = 1; i <= MAXV; i++) {
//        g->degree[i] = 0;
//    }
//
//    for(int i = 1; i <= MAXV; i++) {
//        g->edges[i] = NULL;
//    }
//}
//
//void insertEdge(graph *g, int x, int y, bool directed) {
//
//    struct edgenode *p = NULL;
//    p = (struct edgenode*)malloc(sizeof(struct edgenode));
//    p->y = y;
//    p->weight = NULL;
//    p->next = g->edges[x];
//
//    g->edges[x] = p;
//    g->degree[x] ++;
//
//    if(directed == false)
//        insertEdge(g, x, y, true);
//    else
//        g->nedges ++;
//}
//
//void readGraph(graph *g, bool directed) {
//    int m;
//    int x, y;
//
//    initializeGraph(g, directed);
//    scanf("%d %d", &(g->nvertices), &m);
////    cin >> g->nvertices;
//  //  cin >> m;
//    for(int i = 1; i <= m; i++) {
//    //    cin >> x >> y;
//	scanf("%d %d", &x, &y);
//
//        insertEdge(g, x, y, directed);
//    }
//}
//
//
//void printGraph(graph *g) {
//
//    edgenode *p;
//    for(int i = 1; i <= g->nvertices; i++) {
//	printf("%d : ", i);
//	//cout <<i<<": "<<endl;
//        p = g->edges[i];
//
//        while(!p) {
//           // cout <<p->y<<endl;
//	    printf("p->y: ", p->y);
//            p = p->next;
//        }
//        printf("\n"); //cout <<" "<<endl;
//    }
//}
//
//
