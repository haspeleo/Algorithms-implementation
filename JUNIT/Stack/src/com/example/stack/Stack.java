package com.example.stack;

public class Stack implements StackExercice {
	
	private static final int MAX = 30;
	public int next;  //index in the stack  
	private String [] stack;
	public static int nbElements;
	
	public Stack(int s) {
		stack = new String [s];
		next = 0;
		Stack.nbElements = 0;
	}

	public String pop() throws StackEmptyException {
		
		String last = stack[next - 1];
		Stack.nbElements --;
		return last;
	}

	public void push(String item) {
		
		stack[next++] = item;
		Stack.nbElements ++;
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
