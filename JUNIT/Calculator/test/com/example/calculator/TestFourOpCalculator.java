package com.example.calculator;

import junit.framework.Assert;

import org.junit.Test;

public class TestFourOpCalculator {
	
	FourOpCalculator f = new FourOpCalculator();
	
	@Test
	public final void testAdd() {
		
		Assert.assertEquals(4, f.add(2, 2));
		Assert.assertEquals(0, f.add(-1, 1));
		Assert.assertEquals(2, f.add(1, 1));
	}

	@Test
	public final void testSub() {
		
		Assert.assertEquals(0, f.sub(1, 1));
		Assert.assertEquals(2, f.sub(4, 2));
		
	}

	@Test
	public final void testMul() {
		
		Assert.assertEquals(0, f.mul(0, -1));
		Assert.assertEquals(-1, f.mul(1, -1));
	}

	@Test
	public final void testDiv() {
		
		Assert.assertEquals(0, f.div(0, 1));
		Assert.assertEquals(0, f.div(1, 2));
	}

}
