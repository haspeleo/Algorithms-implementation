#include<cstdlib>
#include <iostream>



#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(struct node* root) {
   root = NULL;
}

BinaryTree::BinaryTree(const BinaryTree& orig) {
}

BinaryTree::~BinaryTree() {
}

/*Helper functions*/

struct node * BinaryTree::allocateNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    //struct node* newNode = new(struct(node); //allocate with new instead of sizeof
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node * BinaryTree::insertNode(struct node * &node, int data) {

    struct node* newNode = allocateNode(data);

    if (node == NULL) {
        node = allocateNode(data);
    } else {

        if (data < node->data)
            newNode = insertNode(node->left, data);
        else
            newNode = insertNode(node->right, data);
    }
}

int BinaryTree::lookup(struct node* node, int target) { //could be written using while loop
    if(node == NULL) return -1; //TO FIX
    else {
        struct node* current = node;
        if(current->data == target) {
            return current->data;
        }
        else {
            if(current->data < target)
                return (lookup(current->right, target));
            else
                return (lookup(current->left, target));
        }
    }
}

/*Helper functions*/

/*tree manipulating functions */

void BinaryTree::printTree(struct node* node) {
    if(node == NULL) {
        return; //cout <<"Empty tree !!"<<endl;
    }
    else {
        printTree(node->left);
        cout <<node->data<<" ";
        printTree(node->right);
    }
}

void BinaryTree::printTreePostOrder(struct node* node) {
    if(node == NULL) {
        return; //cout <<"Empty tree !!"<<endl;
    }
    else {
        printTree(node->left);
        printTree(node->right);
        cout <<node->data<<" ";
    }
}

void BinaryTree::printTreePreOrder(struct node* node) {
    if(node == NULL) {
        return; //cout <<"Empty tree !!"<<endl;
    }
    else {
        printTree(node->right);
        printTree(node->left);
        cout <<node->data<<" ";
    }
}

int BinaryTree::minValue(struct node* node) {
    struct node* current = node;
    while(current->left) {
        current = current->left;
    }
    return current->data;
}

int BinaryTree::maxValue(struct node* node) {
    struct node* current = node;
    while(current->right) {
        current = current->right;
    }
    cout <<" - - - "<<endl;
    return current->data;
}

bool BinaryTree::hasPathSum(struct node* node, int sum) {
    int subSum = 0;
    if(node == NULL) {
        return (sum == 0);
    }
    else {
        struct node* current = node;
        subSum = sum - current->data;
        return (hasPathSum(current->left, subSum)
                || hasPathSum(current->right, subSum));
    }
}

/*helper functions for printing the tree paths*/
void BinaryTree::printArray(int ints[], int len) {
    for(int i = 0; i < len; i++) {
        cout <<ints[i]<<" ";
    }
    cout <<" "<<endl;
}

void BinaryTree::printPathsRecursively(struct node* node, int path[], int pathLen) {
    if(node == NULL) return;
    //append this node to the path array
    path[pathLen] = node->data;
    pathLen ++;
    if(node->left == NULL && node->right == NULL) {
        printArray(path, pathLen);
    }
    else {
        printPathsRecursively(node->left, path, pathLen);
        printPathsRecursively(node->right, path, pathLen);
    }
}

void BinaryTree::printTreePaths(struct node * node) {
    int path[1000];
    printPathsRecursively(node, path, 0);
}

void BinaryTree::mirror(struct node* node) {
    if (node == NULL) return;
    else {
        struct node * temp = NULL;

        mirror(node->left);
        mirror(node->right);

        //swap(node->left, node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

}

bool BinaryTree::sameTree(struct node * a, struct node * b) {
    if (a == NULL && b == NULL) return true;
    else
    if (a != NULL && b != NULL) {
     return (sameTree(a->left, b->left)
             && sameTree(a->right, b->right));
    }
    else return false;
}
