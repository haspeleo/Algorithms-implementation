package com.example.largest;


public class Main {

	private static final int SIZE = 10;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		
		int [] arr = new int[SIZE];
		
		for (int i = 0; i < SIZE; i ++) {
			
			arr[i] = 2 * i; 
		}
	
		
		int max = Largest.largest(arr);
		System.out.println(max);
		
		
	}

}
