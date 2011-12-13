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
		TestSuite suite = new TestSuite("Suite de test pour FourOpCalculator");
		//$JUnit-BEGIN$
		suite.addTest(new TestSuite(TestFourOpCalculator.class));
		//suite.addTest(new TestSuite(ExtendedCalculatorTest.class));//add more tests
		//$JUnit-END$
		return (Test) suite;
		}
	
}


/** Ant script
<?xml version="1.0" encoding="ISO-8859-1" ?>
<project name="TestAnt1" default="all">
   <description>GŽnŽration de l'application</description>
     <property name="bin" location="bin"/>
        <property name="src" location="src"/>
        <property name="build" location="build"/>
        <property name="doc" location="${build}/doc"/>
        <property name="lib" location="${build}/lib"/>
        <property name="junit_path" value="junit.jar"/>
        <target name="test" depends="compil" description="Executer les tests avec JUnit">
           <junit fork="yes" haltonerror="true" haltonfailure="on" printsummary="on">
              <formatter type="plain" usefile="false" />
              <test name="ExecuterLesTests"/>
              <classpath>
                 <pathelement location="${bin}"/>
                 <pathelement location="${junit_path}"/>
              </classpath>
           </junit>
        </target>
</project>

*/