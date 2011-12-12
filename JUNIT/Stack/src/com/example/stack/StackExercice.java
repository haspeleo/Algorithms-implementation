package com.example.stack;


public interface StackExercice {
	
	
	/**
	 * Return and remove the most recent item from the top of the stack.
	 * Throws StackEmptyException if stack is empty.
	 */
	
	public String pop() throws StackEmptyException;
	
	/**
	 * add an item on the top of the stack 
	 */
	
	public void push (String item);
	
	/**
	 * Return but not remove the most recent element from the top 
	 * of the stack.
	 */
	
	public String top() throws StackEmptyException;
	
	/**
	 * Returns true if the stack is empty
	 */
	public boolean isEmpty();
	
	

	/**
	 * Returns true if the stack is full
	 */

	public boolean isFull();


}
