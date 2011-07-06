#include <vector>

#include <Edge.h>

vector<Node*> nodes;

class Node
{
public:
	Node(char id)
		: id(id), previous(NULL),
		distanceFromStart(INT_MAX)
	{
		nodes.push_back(this);
	}
public:
	char id;
	Node* previous;
	int distanceFromStart;
};
