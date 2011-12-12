package com.example.stack;

public class Stack implements StackExercice {
	
	private static final int MAX = 10;
	private int next;  //index in the stack  
	private String [] stack;
	
	public Stack(int s) {
		stack = new String [s];
		setNext(0);
	}

	public String pop() throws StackEmptyException {
		
		return stack[getNext() - 1];
	}

	public void push(String item) {
		
		stack[getNext()] = item;
	}

	public String top() throws StackEmptyException {
		
		return stack[getNext()];
	}

	public boolean isEmpty() {
		
		return (getNext() == 0);
	}

	public boolean isFull() {
		
		return (getNext() == MAX);
	}

	public int getNext() {
		return next;
	}

	public void setNext(int next) {
		this.next = next;
	}

	
}//class
