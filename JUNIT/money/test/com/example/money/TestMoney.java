package com.example.money;

import junit.framework.TestCase;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TestMoney extends TestCase {

	//private Money m1;
	//private Money m2;
	
	public TestMoney(String string) {
		// TODO Auto-generated constructor stub
	}

	@Before
	protected void setUp() throws Exception {
		//common fixture for all tests
		//m1 = new Money(12, "USD");
		//m1 = new Money(12, "USD");
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
		
		Assert.assertTrue(equals(expected, result));
	}
	
	
	/*TestCase test = new TestMoney("Simple Add") {
		public void runTest() {
			testAdd();
		}
	};*/
	
	
	/*public static Test suite() {
	    TestSuite suite= new TestSuite();
	    suite.addTest(
	        new TestMoney("Add function") {
	            protected void runTest() { testAdd(); }
	        }
	    );
	    return (Test) suite;
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
