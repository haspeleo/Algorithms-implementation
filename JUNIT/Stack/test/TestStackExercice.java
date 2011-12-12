import static org.junit.Assert.*;
import junit.framework.TestCase;

import org.junit.Test;

import com.example.stack.Stack;


public class TestStackExercice extends TestCase {

	
	
	Stack stack = new Stack(10);
	
	
	@Test
	public void testPush(String item) { 
		
		stack.push("one");
		
		assertEquals(1, stack.getNext());
		
	}
	
	@Test
	public void testPop() {
		
	}
	
	@Test 
	public void testTop() {
		
	}
	
	@Test 
	public void testIsEmpty() {
		assertEquals(true, stack.isEmpty());
	}
	
	@Test 
	public void tesIsFull() {
		assertEquals(true, stack.isFull());
	}
	
	
	

	

}//class
