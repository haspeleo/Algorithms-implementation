#ifndef BINARYTREE_H
#define	BINARYTREE_H

struct node {
    int data;
    struct node* left;
    struct node* right;
};

class BinaryTree {
public:
    BinaryTree(struct node* root);
    BinaryTree(const BinaryTree& orig);
    virtual ~BinaryTree();

    struct node * allocateNode(int data);

    int lookup(BinaryTree &T, int target);

    /*tree manipulating functions */

    struct node * insertNode(struct node*& node, int data);

    int lookup(struct node* node, int target); //could be written using while loop

    void printTree(struct node* node);

    void printTreePostOrder(struct node* node);

    void printTreePreOrder(struct node* node);


    int minValue(struct node* node);

    int maxValue(struct node* node);

    bool hasPathSum(struct node* node, int sum);

    /*helper functions for printing the tree paths*/
    void printArray(int ints[], int len);

    void printPathsRecursively(struct node* node, int path[], int pathLen);

    void printTreePaths(struct node * node);

    void mirror(struct node* node);

    bool sameTree(struct node * a, struct node * b);

private:

    node * root;

};

#endif	/* BINARYTREE_H */

