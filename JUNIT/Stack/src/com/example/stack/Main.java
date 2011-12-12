package com.example.stack;

public class Main {

	/**
	 * @param args
	 * @throws StackEmptyException 
	 */
	public static void main(String[] args) throws StackEmptyException {
		
		Stack stack = new Stack(12);
		for (int i = 0; i < 10; i++) {
			stack.push(Integer.toString(i));
		}
		
		for (int i = 0; i < 10; i++) {
			stack.getItem(i);
		}
		
		System.out.println(">> nb Elements: "+Stack.nbElements);
		stack.isEmpty();
		stack.isFull();
		
		
		String top = stack.top();
		System.out.println(top);
		
		stack.pop();
		stack.pop();
		
		System.out.println(">> nb Elements: "+Stack.nbElements);
	}

}
