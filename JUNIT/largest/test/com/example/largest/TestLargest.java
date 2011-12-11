package com.example.largest;

import static org.junit.Assert.*;
import junit.framework.Assert;


import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class TestLargest {

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testLargest() {
		
		/*int [] l = new int [10];
		
		l[0] = 7;
		l[1] = 12;
		l[2] = 9;*/
		
		Assert.assertEquals(9, Largest.largest(new int [] {7, 8, 9}));
		Assert.assertEquals(9, Largest.largest(new int [] {9, 8, 7}));
		Assert.assertEquals(9, Largest.largest(new int [] {8, 9, 7}));
	}
	
	@Test
	public void testDuplicate() {
		Assert.assertEquals(9, Largest.largest(new int [] {9, 9, 8, 9}));
	}
	@Test 
	public void testOneElement() {
		Assert.assertEquals(1, Largest.largest(new int [] {1}));
	}
	@Test
	
	public void testNegative() {
		Assert.assertEquals(-7,	Largest.largest(new int [] {-7, -8, -9}));
	}
	
	@Test
	public void testEmpty() {
		
		try {
			Largest.largest(new int [] {});
			fail("Should have thrown an exception!");
		
		} catch (RuntimeException e) {
			assertTrue(true);
		}
		
		
	}

}
