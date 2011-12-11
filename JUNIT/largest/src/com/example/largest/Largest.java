package com.example.largest;

public class Largest {
	
	
	public Largest(String name) {
		// TODO Auto-generated constructor stub
	}

	public static int largest (int [] list ) {
		
		if(list.length == 0) {
			throw new RuntimeException ("Empty list !!");
		}
		int max = list[0];
		
		for (int i = 0; i < list.length; i ++) {
			
			if(list[i] > max) {
				
				max = list[i];
			}
		}
		
		return max;
	}
	
}
