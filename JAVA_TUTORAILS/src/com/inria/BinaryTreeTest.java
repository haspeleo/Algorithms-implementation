package com.inria;

public class BinaryTreeTest {

  public static void main(String[] args) {
    new BinaryTreeTest().run();
  }

  static class Node {
    Node left;

    Node right;

    int value;

    public Node(int value) {
      this.value = value;
    }
  }

  public void run() {
    // build the simple tree from chapter 11.
    Node root = new Node(5);
    System.out.println("Binary Tree Example");
    System.out.println("Building tree with root value " + root.value);
    insert(root, 100);
    insert(root, 50);
    insert(root, 25);
    insert(root, 75);
    insert(root, 150);
    insert(root, 125);
    insert(root, 175);
    insert(root, 110);
    System.out.println("Traversing tree in order");
    printInOrder(root);
    
  }

  public void insert(Node node, int value) {
    if (value < node.value) {
      if (node.left != null) {
        insert(node.left, value);
      } else {
        System.out.println("  Inserted " + value + " to left of "
            + node.value);
        node.left = new Node(value);
      }
    } else if (value > node.value) {
      if (node.right != null) {
        insert(node.right, value);
      } else {
        System.out.println("  Inserted " + value + " to right of "
            + node.value);
        node.right = new Node(value);
      }
    }
  }

  public void printInOrder(Node node) {
    if (node != null) {
      printInOrder(node.left);
      System.out.println("  Traversed " + node.value);
      printInOrder(node.right);
    }
  }
}

  