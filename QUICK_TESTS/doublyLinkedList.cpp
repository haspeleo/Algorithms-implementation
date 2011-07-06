/*http://www.programminginterview.com/content/linked-lists*/

#include<string> 
#include<iostream>
using namespace std;

//void InitializeNode();
void StartnewNode(node *current);
void add_node_at_end();
void add_node_at_start(string new_name);
void InsertNode(node *current, node *After);
void displayNode(node *current);
void RemoveNode(node *current);
void DeleteAllNodes();

//linked list for the per_names  
struct Node
{														 
char* per_name[20];	 									 
Node *prev;//pionter to the previous node	 		   										  
Node *next;//pionter to the next node; 		 
};

 node *current;
 noe *After;
//create header node list
current = new node;
current->char* = per_name;
current->next = NULL;
current->prev = NULL;

Node *first;
Node *last;


int main()
{		
		for (int i=0; i < 5; i++)
		{
		//current = new NODE;
		current -> per_name = i;
		Start_a_newNode_list(current);
		}
cout<<"\nThe contents of the original list are:\n";

for (current = first; current != NULL; current = current -> next)
cout << "\t" << current -> per_name <<endl;

system ("pause");
return 0;
}

		int MenuChoice;
 
		InitializeNode();
		while(1)
	{
			cout << " 1. Start a_new list" << endl;
			cout << " 2. Add a Node to the end of the list" << endl;
			cout << " 3. Add a Node	to the beginning of the list" << endl;
			cout << " 4. Add a Node at a specified position in the list" << endl;
			cout << " 5. displaying all the person data" << endl;
			cout << " 6. Remove a Node at a specified position from the list" << endl;
			cout << " 7. Delete the entire list" << endl;
			cout << " 8. Exit" << endl;

			cout << "Enter your choice: ";
			cin >> MenuChoice;

			if((MenuChoice < 0) && (MenuChoice > 8))
			{
			 cout << "Invalid Choice" << endl;
			system("Pause Try Again");
			}
		else
			{
			switch(MenuChoice)
			{
			case 1: StartnewNode();
				break;
			case 2: add_node_at_end();
				break;
			case 3: add_node_at_start();
				break;
			case 4: InsertNode();
				break;
			case 5: displayNode();
				break;
			case 6: RemoveNode();
				break;
			case 7: DeleteAllNodes();
				break;
			case 8:
				exit(1);		
		}
	}
	cin.get();  
  }
  
return 0; 

}
// Add node at the begining of the list
void add_node_at_start(string new_name)
 { // Declare a temporary pointer and move it to the start
   node *temp = current;
   while (temp->prev != NULL)
    temp = temp->prev;
   // Declare a new node and link it in
   node *temp2;
   temp2 = new node;
   temp2->name = new_name;  // Store the new name in the node
   temp2->prev = NULL;       // This is the new start of the list
   temp2->next = temp;       // Links to current list
   temp->prev = temp2;
 }

// Add note at the end of the list
void add_node_at_end ()
 { // Declare a temporary pointer and move it to the end
   node *temp = current;
   while (temp->next != NULL)
    temp = temp->next;
   // Declare a new node and link it in
   node *temp2;
   temp2 = new node;
   temp2->name = new_name;  // Store the new name in the node
   temp2->next = NULL;       // This is the new start of the list
   temp2->prev = temp;       // Links to current list
   temp->next = temp2;
 }
// Inserts a node into a specified location
void InsertNode(node *current, node *After)
{
   current->pNext = After->pNext;
   current->prev = After;
   if (After->next != NULL)
      After->next->prev = current;
   else
      last = current;
   After->next = current;
}


// Removes node from specified location
void RemoveNode(node *current)
{
   if (current->prev == NULL)
      first = current->next;
   else
      current->prev->next = current->next;
   if (current->next == NULL)
      last = current->prev;
   else
      current->next->prev = current->prev;
}

// Deletes the entire list
void DeleteAllNodes()
{
   while (first != NULL)
      RemoveNode(first);
}

// Now display each item in list
   for (current = first; pNode != NULL; current = current->next)
   {
      cout <<("\n", current->name);
   }

