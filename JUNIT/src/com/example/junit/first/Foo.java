

package com.example.junit.first;

public class Foo {

	
	private int [] array; 
	
	public Foo(int size) {
		
			array = new int [size];	
	}
	
	public String getHello() {
		
		return "Hello World";
	}
	
	public boolean getTruth() {
		
		return true;
		//return false; //this should fail the test 
	}
	
	public void setElement (int position, int value) throws ArrayIndexOutOfBoundsException {
		
		array[position] = value;
	}
	
	public int getElement(int position) throws ArrayIndexOutOfBoundsException {
		
		return array[position];
	}
	
	
}


