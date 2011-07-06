/* 
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 * http://math.hws.edu/eck/cs225/s03/binary_trees/
 * http://math.hws.edu/javanotes/index.html //JAVA
 * http://www.cmcrossroads.com/bradapp/ftp/src/libs/C++/AvlTrees.html //AVL Trees
 * http://fringe.davesource.com/Fringe/Computers/Languages/CC/Tutorial/tutorial2.html#intro
 * http://algs4.cs.princeton.edu/home/
 * http://codepad.org/ //online-compiler
 * http://www.botskool.com/user/register?destination=online-compiler //botskool compiler
 * http://www.cprogramming.com/tutorial/lesson18.html
 */

#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"

using namespace std;

/*===========================================================================*/
/*                                 MAIN PROGRAM                              */

/*===========================================================================*/

int main(int argc, char** argv) {

    struct node* root = NULL;
    BinaryTree tree(root);

    tree.insertNode(root, 5);
    tree.insertNode(root, 5);
    tree.insertNode(root, 3);
    tree.insertNode(root, 9);
    tree.insertNode(root, 7);
    tree.insertNode(root, 4);
    tree.insertNode(root, 12);
    tree.insertNode(root, 8);
    tree.insertNode(root, 17);
    tree.insertNode(root, 2);

    tree.printTree(root);
    tree.printTreePreOrder(root);
    tree.printTreePostOrder(root);

    cout << ">> Max value of the tree: " << tree.maxValue(root) << endl;

    cout << ">> Min value of the tree: " << tree.minValue(root) << endl;

    cout << ">> lookup is fast for Binay trees O(log(N)):  " << endl;
    int data = 3;
    int searchFor = tree.lookup(root, data);

    if (searchFor != -1)
        cout << "Found: " << data << "; Exists and the value is: " << searchFor << endl;
    else
        cout << "Not Found : " << data << "; does NOT exists " << endl;

    cout << ">> Looking for paths having sum nodes equal to given sum" << endl;
    int sum = 14;
    if (tree.hasPathSum(root, sum)) {
        cout << "Path having node's sum = " << sum << " Exits" << endl;
    } else {
        cout << "No Path having node's sum =  " << sum << endl;
    }

    cout << ">> Printing all paths in a tree" << endl;

    tree.printTreePaths(root);
    cout << "Mirror of a tree" << endl;
    tree.printTreePaths(root);
    tree.mirror(root);
    tree.printTreePaths(root);

    cout << "Checking if two trees are the same structurally :" << endl;
    struct node *root2 = NULL;
    BinaryTree tree2(root2);
    tree2.insertNode(root2, 99);

    bool same = tree.sameTree(root, root2);

    if (same)
        cout << "Same tree" << endl;
    else
        cout << "Trees are differents" << endl;
    return 0;
}

