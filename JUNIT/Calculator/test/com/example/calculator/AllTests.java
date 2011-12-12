package com.example.calculator;

import junit.framework.TestSuite;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({ TestFourOpCalculator.class })

public class AllTests {

	public static Test suite() {
		TestSuite suite =
		new TestSuite("Suite de teste pour les outils de calcul");
		//$JUnit-BEGIN$
		suite.addTest(new TestSuite(TestFourOpCalculator.class));
		//suite.addTest(new TestSuite(ExtendedCalculatorTest.class));
		//$JUnit-END$
		return (Test) suite;
		}
	
}
