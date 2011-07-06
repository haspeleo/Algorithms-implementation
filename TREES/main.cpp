
/*
 * http://math.hws.edu/eck/cs225/s03/binary_trees/
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 * http://www.personal.kent.edu/~rmuhamma/Algorithms/algorithm.html
 * http://www-h.eng.cam.ac.uk/help/tpl/talks/C++graphs.html
 * http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
 * http://www.tenouk.com/Sitemap.html   //c++ tutorial
 * http://math.hws.edu/xJava/MB/index.html //Mandelbrot set :)
 * http://www.java2s.com/Code/Cpp/CatalogCpp.htm //C++ tutorial
 */

#include <cstdlib>
#include<iostream>

#include<math.h>

using namespace std;

typedef struct Node Node;

struct Node {
    int nbWins;
    int nbSims;
    Node *left; //pointer to left subtree
    Node *right; //pointer to right subtree

    Node(int nbWins, int nbSims) {
        this->nbWins = nbWins;
        this->nbSims = nbSims;
        left = NULL;
        right = NULL;
    }
};


void treeInsert(Node *&root, int newnbWins, int newnbSims) {
    if (root == NULL) {
        root = new Node(newnbWins, newnbSims);
        return;
    }
    else if (newnbWins < root->nbWins)

            treeInsert(root->left, newnbWins, newnbSims);
        else
            treeInsert(root->right, newnbWins, newnbSims);
}

int countNbNodes(Node *root) {
    return root == NULL ? 0 : 1 + countNbNodes(root->left) + countNbNodes(root->right);
}

int minValue(Node *root) {
    int min;
    
    if (root->left == NULL)
        min = root->nbWins;
    else {
        min = minValue(root->left);
    }
    return min;
}

int maxValue(Node *root) {
    int max;

    if (root->right == NULL)
        max = root->nbWins;
    else {
        max = maxValue(root->right);
    }
    return max;
}

bool lookupnbWins(Node *root, int searchFor) {
    bool found = false;

    if (root == NULL) {
        found = false;
        return found;
    }
    else if (searchFor == root->nbWins) {
        found = true;
        return found;
    }
    else if (root->nbWins < searchFor){
              found = (lookupnbWins(root->right, searchFor));
              return found;
    }
    else {
              found = (lookupnbWins(root->left, searchFor));
              return found;
    }
}

bool isALeaf(Node *root) {
    if (root->left == NULL && root->right == NULL)
        return true;
    else
        return false;
}

int maxDepth(Node *root) {
    int depth = 0, depthLeft = 0, depthRight = 0;
    if (root == NULL) {
        depth = 0;
        return depth;
    }
    else {
        depthLeft  = maxDepth(root->left);
        depthRight = maxDepth(root->right);
    
        depth = max (depthRight, depthLeft);
        return depth + 1;
    }
}

double scoreUCB (Node *root) {
    double score;
    if (root->nbSims == 0) {
        cout <<"NbSimulations = 0 !"<<endl;
        exit (0);
    }

    score = (root->nbWins / root->nbSims) + sqrt(2 * log(root->nbWins) / root->nbSims);

    return score;
}

void printNodes(Node *root) {
    if (root != NULL) {
        printNodes(root->left);
        
        printNodes(root->right);
        cout <<"NbWins = "<<
                root->nbWins<<" ; NbSims = "<<
                root->nbSims<<" ; UCB value = "<<
                scoreUCB(root)<<endl;
    
    if (isALeaf(root) == true) {
        cout <<">> Leaf Node "<<isALeaf(root)<<endl;
    }
    else {
        cout <<">> NOT leaf Node "<<isALeaf(root)<<endl;
    }
  
    }
}

bool hasPathSum(Node *root, int sum){
    int subSum;
    if (root == NULL) {
        return (sum == 0);
    }
    else {
       subSum = sum - root->nbWins;
       return (hasPathSum(root->left, subSum) || hasPathSum(root->right, subSum));
    }
}


// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
}



void printPathsRecur(Node * node, int path[], int pathLen) {
  if (node==NULL) return;

  // append this node to the path array
  path[pathLen] = node->nbWins;
  pathLen++;

  // it's a leaf, so print the path that led to here
  if (node->left==NULL && node->right==NULL) {
    printArray(path, pathLen);
  }
  else {
  // otherwise try both subtrees
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}

/*
 Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work (see above).
*/
void printPaths(Node * node) {
  int path[1000];
  printPathsRecur(node, path, 0);
}

/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
*/







/** MAIN PROGRAMM **/
int main(int argc, char** argv) {

    Node *root = NULL;

    for (int i = 1; i < 1000; i++) {
        treeInsert(root, rand()%100, i*2);
    }

    /*treeInsert(root, 3, 10);
    treeInsert(root, 9, 7);
    treeInsert(root, 1, 2);
    treeInsert(root, 10, 1);
    treeInsert(root, 5, 5);
    treeInsert(root, 6, 1);
    treeInsert(root, 8, 1);
    treeInsert(root, 7, 3);
    treeInsert(root, 2, 1);
    treeInsert(root, 4, 1);*/
    
    printNodes(root);

    cout <<">>Total number of nodes = "<<countNbNodes(root)<<endl;

    int searchFor = 4;

    if(lookupnbWins(root, searchFor) == true)

        cout <<">> nbWins "<<searchFor<<" found in the Tree"<<endl;
    else
        cout <<">> nbWins "<<searchFor<<" does not exist in the Tree"<<endl;

    cout <<">> Min Value of the tree = "<<minValue(root)<<endl;
    cout <<">> Max Value of the tree = "<<maxValue(root)<<endl;
    
    cout <<"UCB value = "<<scoreUCB(root)<<endl;
    
    double w = 4, s = 1;
    double r;


    r = (w / s) + sqrt(2 * log(w) / s);
    cout <<"UCB value verification =  "<<r<<endl;

    cout<<"MaxDepth = "<<maxDepth(root)<<endl;

    int sumPath = 22;
    if (!hasPathSum(root, sumPath))
        cout <<"No Path of Sum "<<sumPath<<" exits"<<endl;
    else
        cout <<"Path of Sum "<<sumPath<<" exits"<<endl;

        printPaths(root);
    return 0;
}
