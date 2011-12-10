package com.example.junit.first;


import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import junit.framework.*;


public class FooTest extends TestCase {

	protected Foo foo;
	protected int testSize;
	
	//standard constructor 
	
	public FooTest (String name) {
		super(name);
	}
	
	@Before
	//Called before every test execution. It creates new instance of the tested class 
	// and performs some more actions that are necessary for the tests.
	
	public void setUp() throws Exception {
		
		testSize = 3;
		foo = new Foo(testSize);
	}

	
	@Test
	public void testGetHelloWorld() {
		
		System.out.println("testGetHelloWorld");
		String result = "Hello World";
		Assert.assertEquals(result, foo.getHello());
	
	}

	public void testTruth() {
		Assert.assertEquals(true, foo.getTruth());
	}
	
	public void testSetElement() {
		//check that an exception "ArrayIndexOutOfBounds" is thrown when trying to access 
		// an element at position "size"
		
		try {
			System.out.println("testSetElement, exception throwed: --> ");
			foo.setElement(testSize, 0);
			// Assert.fail is raised if exception is not catched
			Assert.fail("setElement should raise an Exception");
			
		} catch (Exception e) {
			System.out.println(e.toString());
		}
		//test with valid parameters, no exception supposed to be thrown
		
		try {
			System.out.println("testSetElement - [OK]");
			int position = testSize - 1;
			int result = 10;
			
			foo.setElement(position, result);
			Assert.assertEquals(result, foo.getElement(position));
		} catch (Exception e) {
			System.out.println(e.toString());
		}
		
		
		
	}
	
	public void testGetElement(int position) {
		
		foo.setElement(2, 10);
		
		int result = 10;
		Assert.assertEquals (result, foo.getElement(2));
	}
	
	@After
	public void tearDown() throws Exception {
	}

	
}
