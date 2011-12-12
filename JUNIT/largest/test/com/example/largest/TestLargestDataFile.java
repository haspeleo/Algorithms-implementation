package com.example.largest;



import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import org.junit.Test;

import junit.framework.TestCase;

public class TestLargestDataFile  extends TestCase {

	public TestLargestDataFile (String name ) {
		super(name);
	}
	
	 /*Run all the tests in testdata.txt(does not test exception case)
	 * You will get an error if any I/O file operations goes wrong. 
	 */
	
	
	@Test
	public void testFromFile() throws Exception {
		
		String line; 
		BufferedReader rdr = new BufferedReader(new FileReader("testdata.txt"));
		
		while ((line = rdr.readLine()) != null) {
			if (line.startsWith("#")) {
				continue; //ignore comments
			}
			StringTokenizer st = new StringTokenizer(line);
			if(!st.hasMoreTokens()) {
				continue; //blank line 
			}
			
			//Get the expected value
			String val = st.nextToken();
			int expected = Integer.valueOf(val).intValue();
			
			//And arguments to largest 
			
			@SuppressWarnings("rawtypes")
			ArrayList arguments_list = new ArrayList();
			while(st.hasMoreElements()) {
				arguments_list.add(Integer.valueOf(st.nextToken()));
				
			}
			//Transfer object into native array
			int [] arguments = new int [arguments_list.size()];
			
			for (int i = 0; i < arguments_list.size(); i++) {
				arguments [i] = ((Integer)arguments_list.get(i)).intValue();
			}
			//And finally run the asserts
			
			assertEquals(expected, Largest.largest(arguments));
			
		}	
	}
}