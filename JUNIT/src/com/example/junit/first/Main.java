package com.example.junit.first;

public class Main {

	public static void main (String [] args ) {
		
		Foo f = new Foo(10);
		String hello = f.getHello();
		
		System.out.println(hello);
		
		System.out.println(f.getTruth());
		
		f.setElement(1, 10);
		f.setElement(2, 12);
		
		System.out.println(f.getElement(2));
		
	}
	
}
