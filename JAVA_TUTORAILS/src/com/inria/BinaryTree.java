package com.inria;

public class BinaryTree {

    private Node root;

private static class Node {

    Node left;
    Node right;
    int data;
public Node(int data) {
     left = null;
     right = null;
     this.data = data;

        }
    }
//create empty binary tree

public void BinaryTree() {
    root = null;
}

//lookup for a target --using recusion

public boolean lookup(int data) {

    if (root == null) return false;
    else
        if (root.data < data )
            return (lookup(root.data));
          else
              return (lookup(root.data));

    return false;
    
    
    }
}
