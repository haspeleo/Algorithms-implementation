package com.example.stack;

public class Stack implements StackExercice {
	
	public static final int MAX = 30;
	public int next;  //index in the stack  
	private String [] stack;
	public static int nbElements = 0;
	
	public Stack(int s) {
		stack = new String [s];
		next = 0;
		nbElements = 0;
	}

	public String pop() throws StackEmptyException {
	
		return stack[next - 1];		
	}

	public void push(String item) {
		
		stack[next++] = item;
		nbElements ++;
	}

	public String top() throws StackEmptyException {
		
		return stack[next - 1];
	}

	public boolean isEmpty() {
		
		return (nbElements == 0);
	}

	public boolean isFull() {
		
		return (nbElements == MAX);
	}

	public void getItem(int i) {
		
		System.out.println("Item["+i+"]= "+ stack[i]);
	}


	
}//class
