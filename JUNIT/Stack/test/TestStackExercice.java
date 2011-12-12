import static org.junit.Assert.*;
import junit.framework.TestCase;

import org.junit.Test;

import com.example.stack.Stack;
import com.example.stack.StackEmptyException;


public class TestStackExercice extends TestCase {
	
	Stack stack = new Stack(10);
		
	@Test
	public void testPush(String item) { 
		
		stack.push("one");
		stack.push("two");
		//stack.push("three");
		System.out.println("Nb elements: "+Stack.nbElements);
		assertEquals(2, Stack.nbElements);
		
	}
	
	@Test
	public void testPop() {
		
	}
	
	@Test 
	public void testTop() {
		stack.push("four");
		stack.push("five");
		stack.push("six");
		try {
			assertEquals("six", stack.top());
		} catch (StackEmptyException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	@Test 
	public void testIsEmpty() {
	
		assertEquals(false, stack.isEmpty());
	}
	
	@Test 
	public void tesIsFull() {
		
		assertEquals(true, stack.isFull());
	}
	
	
	

	

}//class
