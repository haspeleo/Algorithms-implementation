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
		stack.push("three");
		stack.push("four");
		System.out.println("::Nb elements: "+Stack.nbElements);
		assertEquals(4, Stack.nbElements);	
	}
	
	@Test
	public void testPop() throws StackEmptyException {
		stack.push("one");
		stack.push("two");
		
		assertEquals("two", stack.pop());
	}
	
	@Test 
	public void testTop() {
		
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
		
		assertEquals(false, stack.isFull());
	}
	
	
	

	

}//class
