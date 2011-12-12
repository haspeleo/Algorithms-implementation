package com.example.money;

import junit.framework.TestCase;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TestMoney extends TestCase {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	public boolean equals(Money m1, Money m2) {
		
		if( m1.amount() == m2.amount() 
		    && m1.currency() == m2.currency())
			return true; 
		else 
			return false;
	}
	
	@Test
	public void testAdd() {
		Money m1 = new Money(12, "CHF");
		Money m2 = new Money(14, "CHF");
		Money result = m1.add(m2);
		Money expected = new Money(26, "CHF");
		
		//Assert.assertEquals(expected, result);
		//Assert.assertTrue(expected.equals(result));
		Assert.assertTrue(equals(expected, result));
	}
	
	/*public void testEquals() {
	    Money m12CHF= new Money(12, "CHF");
	    Money m14CHF= new Money(14, "CHF");

	    Assert.assertTrue(!m12CHF.equals(null));
	    Assert.assertEquals(m12CHF, m12CHF);
	    Assert.assertEquals(m12CHF, new Money(12, "CHF")); // (1)
	    Assert.assertTrue(!m12CHF.equals(m14CHF));
	}*/
	
	//Overriding Java method equals to compare two Money objects
	/*public boolean equals(Object anObject) {
		
		if(anObject instanceof Money) {
			Money aMoney = (Money)anObject;
			return ((aMoney.currency()).equals(currency())
					&& (amount() == aMoney.amount());
		}
		return false;
	}*/

}
