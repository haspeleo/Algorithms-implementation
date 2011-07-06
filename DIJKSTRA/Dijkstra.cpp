#include <vector>
#include "Node.h"
#include "Edge.h"


void PrintShortestRouteTo(Node* destination)
{
	Node* previous = destination;
	cout << "Distance from start: "
		<< destination->distanceFromStart << endl;
	while (previous)
	{
		cout << previous->id << " ";
		previous = previous->previous;
	}
	cout << endl;
}


// Return distance between two connected nodes
int Distance(Node* node1, Node* node2)
{
	const int size = edges.size();
	for(int i=0; i<size; ++i)
	{
		Edge* edge = edges.at(i);
		if (edge->Connects(node1, node2))
		{
			return edge->distance;
		}
	}
	return -1; // should never happen
}


// Does the 'nodes' vector contain 'node'

bool Contains(vector<Node*>& nodes, Node* node)
{
	const int size = nodes.size();
	for(int i=0; i<size; ++i)
	{
		if (node == nodes.at(i))
		{
			return true;
		}
	}
	return false;
}





// Return all nodes adjacent to 'node' which are still
// in the 'nodes' collection.
vector<Node*>* AdjacentRemainingNodes(Node* node)
{
	vector<Node*>* adjacentNodes = new vector<Node*>();
	const int size = edges.size();
	for(int i=0; i<size; ++i)
	{
		Edge* edge = edges.at(i);
		Node* adjacent = NULL;
		if (edge->node1 == node)
		{
			adjacent = edge->node2;
		}
		else if (edge->node2 == node)
		{
			adjacent = edge->node1;
		}
		if (adjacent && Contains(nodes, adjacent))
		{
			adjacentNodes->push_back(adjacent);
		}
	}
	return adjacentNodes;
}




// Find the node with the smallest distance,
// remove it, and return it.
Node* ExtractSmallest(vector<Node*>& nodes)
{
	int size = nodes.size();
	if (size == 0) return NULL;
	int smallestPosition = 0;
	Node* smallest = nodes.at(0);
	for (int i=1; i<size; ++i)
	{
		Node* current = nodes.at(i);
		if (current->distanceFromStart <
			smallest->distanceFromStart)
		{
			smallest = current;
			smallestPosition = i;
		}
	}
	nodes.erase(nodes.begin() + smallestPosition);
	return smallest;
}




void Dijkstras()
{
	while (nodes.size() > 0)
	{
		Node* smallest = ExtractSmallest(nodes);
		vector<Node*>* adjacentNodes =
			AdjacentRemainingNodes(smallest);
		const int size = adjacentNodes->size();
		for (int i=0; i<size; ++i)
		{
			Node* adjacent = adjacentNodes->at(i);
			int distance = Distance(smallest, adjacent) +
				smallest->distanceFromStart;
			if (distance < adjacent->distanceFromStart)
			{
				adjacent->distanceFromStart = distance;
				adjacent->previous = smallest;
			}
		}
		delete adjacentNodes;
	}
}




void DijkstrasTest() {

	Node* a = new Node('a');
	Node* b = new Node('b');
	Node* c = new Node('c');
	Node* d = new Node('d');
	Node* e = new Node('e');
	Node* f = new Node('f');
	Node* g = new Node('g');
	Edge* e1 = new Edge(a, c, 1);
	Edge* e2 = new Edge(a, d, 2);
	Edge* e3 = new Edge(b, c, 2);
	Edge* e4 = new Edge(c, d, 1);
	Edge* e5 = new Edge(b, f, 3);
	Edge* e6 = new Edge(c, e, 3);
	Edge* e7 = new Edge(e, f, 2);
	Edge* e8 = new Edge(d, g, 1);
	Edge* e9 = new Edge(g, f, 1);
	a->distanceFromStart = 0; // set start node
	Dijkstras();
	PrintShortestRouteTo(f);
	// Node / Edge memory cleanup snipped
}
