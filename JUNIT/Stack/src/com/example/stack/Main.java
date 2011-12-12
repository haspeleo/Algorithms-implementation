package com.example.stack;

public class Main {

	/**
	 * @param args
	 * @throws StackEmptyException 
	 */
	public static void main(String[] args) throws StackEmptyException {
		
		Stack stack = new Stack(10);
		
		for (int i = 0; i < 5; i++) {
			stack.push(Integer.toString(i));
		}
		
		for (int i = 0; i < 5; i++) {
			stack.getItem(i);
		}
		
		
		String str1 = stack.pop();
		String str2 = stack.pop();
		System.out.println(str1);
		System.out.println(str2);
		System.out.println(">> nb Elements: "+Stack.nbElements);
		
		
	}

}
