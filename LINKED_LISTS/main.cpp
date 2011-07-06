/*
 * http://www.bien-programmer.fr/codage.php#bibliotheque
 * http://depinfo.mines.inpl-nancy.fr/Members/thomas.darcet/ascenseur/projetascenseur
 * http://www.c-cplusplus.com/c-program-using-arrays-to-implement-working-of-lift-in-multi-story-buildings
 * http://www.angelfire.com/trek/software/elevator.html
 */


#include <cstdlib>
#include<iostream>
#include <assert.h>
#include <list>

using namespace std;

struct node {
    int data;
    struct node *next;
};


struct node * buildOneTwoThree() {

    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    assert(head   = (struct node*) malloc(sizeof(struct node)));
    assert(second = (struct node*) malloc(sizeof(struct node)));
    assert(third  = (struct node*) malloc(sizeof(struct node)));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

int length(struct node* head) {
    
    int count = 0;
    struct node* current = head;
    if (head == NULL) {
        cout <<"Empty list ! "<<endl;
    }
    while(current != NULL) {
        count ++;
        current = current->next;
    }
    return count;
}

void pushAtHead(struct node *& head, int data) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

void pushAtEnd(struct node*& head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    struct node *current = NULL;
    current = head;
    /*special case for an insert in an empty list*/
    if (current == NULL) {
        head = newNode;
    }
    else {
        
        while (current->next != NULL){
        current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct node* head) {
    struct node * current = NULL;
    current = head;
    cout <<"\n- - - - - - List- - - - - - - - "<<endl;
    while (current != NULL){
        cout <<current->data<<" ";
        current = current->next;
    }
    cout <<"\n- - - - - - - - - - - - - - - - -"<<endl;
}

struct node * copyList(struct node * &head) {
    struct node* current = head;
    struct node* newList = NULL;
    struct node* tail = NULL;

    while (current != NULL) {
        if (newList == NULL) {
            newList = (struct node*)malloc (sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = (struct node*)malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
    return newList;
}

struct node* copyListRecursive(struct node* &head) {
    
    struct node* current = head;

    if (current == NULL) {
        return NULL;
    }
    else {
        struct node* newList = (struct node*)malloc(sizeof(struct node));
        newList->data = current->data;
        newList->next = copyListRecursive(current->next);
    return newList;
    }
}

int count(struct node*& head, int search) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        if (current->data == search) {
            count ++;
        }
    current = current->next;       
    }
    return count;
}

int getNTh(struct node* &head, int index) {
    struct node* current = head;
    int listSize = length(head);
    int i, count = 0;
    assert(index <= listSize && index > -1);

    while (current != NULL && (index != count)) {
        count ++;
        current = current->next;
    }
    return (current->data);
}

void deleteList(struct node* &head) {
    struct node *current = head;
    struct node* next;
    while (current != NULL) {
        next =  current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int pop(struct node* &head) {
    struct node* current = head;
    struct node* newHead = NULL;

    int data = current->data;

    newHead = current->next;
    free(current);
    head = newHead; 
    
    return (data);
}

void insertNTh(struct node* &head, int index, int data) {

    if(index == 0) {
        pushAtHead(head, data);
    }
    else {
        struct node *current = head;

        for(int i = 0; i< index - 1; i++) {
            assert(current->next != NULL);
            current = current->next;
        }
        assert(current != NULL);
        pushAtHead(current->next, data);
    }
}

void sortedInsert(struct node* &head, struct node* newNode) {
    struct node* current = head;
    if (head == NULL || current->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        //Locate the node before the point of insertion
        while (current->next != NULL && current->next->data < newNode->data ) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }  
}

void insertSort(struct node* &head) {
    struct node* current = head;
    while(current->next != NULL) {
        sortedInsert(head, current);
        current = current->next;
    }
}

void appendList(struct node* &l1, struct node*&l2) {
    if(l1 == NULL) {
        l1 = l2;
        l2 = NULL;
    }
    else {
        struct node* current = l1;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = l2;
        l2 = NULL;
    }
}

void frontBackSplit(struct node *source, struct node* &front, struct node* &back) { 

    if(source == NULL || source->next == NULL) {
        front = source;
        back = NULL;
    } else {
        struct node* fast = source;
        struct node* slow = source;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }

        }
        front = source;       
        back = slow->next;
    }
}

void removeAdjacentDuplicate(struct node* &head) {
    struct node* current = head;
    if(current == NULL) return;
    else {
        while(current->next != NULL) {
            if(current->data == current->next->data) {
                struct node* jump = current->next->next;
                free(current->next);
                current->next = jump;
            }
            else {
                current = current->next;
            }
        }

    }
}

void moveNode(struct node* & dest, struct node* &source) {
    struct node *currentS = source;
    struct node *currentD = dest;    
    
    dest = currentS;
    source = source->next;
    currentS->next = currentD;
    dest = currentS;
    
}

void alternatingSplit(struct node* source, struct node*& aRef, struct node*& bRef) {
    struct node * a = NULL;
    struct node * b = NULL;
    
    assert(source != NULL);
    
    struct node* current = source;
    while(current != NULL) {
        
        moveNode(a, current);
        
        if (current != NULL) {
            moveNode(b, current);
        }
    }
    aRef = a;
    bRef = b;
}

struct node* shuffleMerge(struct node*& aRef, struct node*& bRef) {
    struct node* merged = NULL;
    
    struct node* currentA = aRef;
    struct node* currentB = bRef;
   
    while (currentA != NULL || currentB != NULL) {
        moveNode(merged, currentA);
        if (currentB != NULL) {
            moveNode(merged, currentB);
        }
    }
    if(currentA == NULL) {
        while(currentB != NULL) {
            appendList(merged, currentB);
        }
    }
    if(currentB == NULL) {
        while(currentA != NULL) {
            appendList(merged, currentA);
        }
    }    
    return merged;
}

struct node* predecessor(struct node* head, int x) {
    if(head == NULL || head->next == NULL) {
        cout <<"Empty list"<<endl;
        return NULL;
    }
    struct node *pred = head;    
    if(pred->next->data == x) {
        return pred;
    }
    else {
        return(predecessor(pred->next, x));
    }
}

struct node * lookup(struct node * head, int searchFor) {
    if(head == NULL) return NULL;
    if(head->data == searchFor) {
        return (head);
    }
    else {
        return(lookup(head->next, searchFor));
    }
}

//void deleteElement(struct node *& head, int item) {
//    if(head == NULL) return;
//    else {
//        struct node * current = head;
//        if(current->next->data != item) {
//            current->next = current->next->next;
//        }
//        else {
//            deleteElement(current->next, item);
//        }
//    }
//}

void deleteElement(struct node *& head, int item) {
    struct node * searched = lookup(head, item);
    struct node * pred = predecessor(head, item);

    pred->next = searched->next;
    free(searched);
}


/*===========================================================================*/
/*                          MAIN PROGRAM                                     */
/*===========================================================================*/

int main(int argc, char** argv) {

    struct node* head = buildOneTwoThree();
    cout <<"longueur de la liste: "<<length(head)<<endl;

    pushAtHead(head, 9);
    pushAtEnd(head, 71);
    printList(head);
    pushAtEnd(head, 71);


    struct node* myList = NULL;
    myList = copyList(head);
    printList(myList);
    myList = copyListRecursive(head);
    printList(myList);

    int search = 71;
    int nbOccurence = count(head, search);
    cout <<"Number of occurance of "<<search<<" = "<<nbOccurence<<endl;

    int index = 1;
    int nth = getNTh(head, index);
    cout <<"The data of "<<index<<"th node = "<<nth<<endl;
    cout <<"longueur de la liste: "<<length(head)<<endl;

    
    int first = pop(head);
    cout <<"Poping one element : "<<first<<endl;
    printList(head);
    cout <<"longueur de la liste: "<<length(head)<<endl;

    cout <<"Deleting the hole list "<<endl;
    deleteList(head);
    printList(head);

    insertNTh(head, 0, 42);
    insertNTh(head, 1, 5);
    insertNTh(head, 1, 71);
    printList(head);

//    cout<<"Sorting list elements in an increasing order"<<endl;
//    insertSort(head);
//    printList(head);

    cout <<"This is a sorted list"<<endl;
    deleteList(head);
    for(int i = 0; i < 5; i++) {
        pushAtEnd(head, i * 2);
    }
    printList(head);
    cout <<"Searching for one element: "<<endl;
    //struct node* wanted = lookup(head, 4);
    cout <<"Searching for 4 => "<<lookup(head, 4)->data<<endl;
    cout <<"given an element, insert it in a sorted list"<<endl;
    int value = 7;
    struct node* newNode = (struct node*)malloc(sizeof (struct node));
    newNode->data = value;
    sortedInsert(head, newNode);
    printList(head);

    cout <<"Append a second list to the first one"<<endl;
    appendList(head, myList);
    printList(head);
    cout <<"Splitting the list in two"<<endl;
    struct node* front = NULL;
    struct node* back = NULL;
    frontBackSplit(head, front, back);
    printList(head);
    printList(front);
    printList(back);

    pushAtHead(head, 1);
    pushAtHead(head, 1);
    pushAtHead(head, 2);printList(head);
    pushAtHead(head, 0);
    pushAtHead(head, 2);
    
    cout <<"removing duplicate"<<endl;
    printList(head);
    removeAdjacentDuplicate(head);
    printList(front);

    cout <<"Moving node from front node from source to front in destination"<<endl;
    struct node *l1 = NULL;
    struct node *l2 = NULL;
    
    pushAtHead(l1, 2);pushAtHead(l1, 81);
    pushAtHead(l2, 4);pushAtHead(l2, 71);
    printList(l1);
    printList(l2);
    moveNode(l1, l2);
    printList(l1);
    printList(l2);
    printList(head);

    cout<<"alternating split list in two smaller lists"<<endl;
    struct node *a = NULL;
    struct node *b = NULL;
    deleteList(head);
    for(int i = 0; i < 10; i++) {
        pushAtEnd(head, i);
    }
    printList(head);
    alternatingSplit(head, a, b);
    printList(head);
    printList(a);
    printList(b);
    cout <<"Shuffle merge of two lists"<<endl;

    struct node * merged = shuffleMerge(a, b);
    printList(merged);
    cout <<"predecessor of an element:"<<endl;
    struct node *pred = predecessor(merged, 5);
    cout <<"Predeccessor is: "<<pred->data<<endl;
    cout <<"Deleting one element 5 "<<endl;
    deleteElement(merged, 5);
    printList(merged);

    
    cout<<" ===== Quick using of lists using STL ====="<<endl;
    list<char> listObject;
    for (int i = 0; i < 10; i++) {
        listObject.push_back('A'+i);
    }
    cout <<"Size of listObject = "<<listObject.size()<<endl;

    list<char>::iterator ii;
    cout<<"Contents: ";

    while(!listObject.empty()) {
       ii = listObject.begin();
        cout<< *ii<<" ";
        listObject.pop_front();
    }
    
    return 0;
}

