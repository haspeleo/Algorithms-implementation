package income;

	import static org.junit.Assert.fail;
	import junit.framework.Assert;
	import income.method.ICalcMethod;
	import org.easymock.EasyMock;
	import org.junit.Before;
	import org.junit.Test;

	public class TestIncomeCalculator {

		private ICalcMethod calcMethod;
		private IncomeCalculator calc;

		@Before
		public void setUp() throws Exception {
			calcMethod = EasyMock.createMock(ICalcMethod.class);
			calc = new IncomeCalculator();
		}

		@Test
		public void testCalc1() throws CalcMethodException, PositionException {
			// Setting up the expected value of the method call calc
			EasyMock.expect(calcMethod.calc(Position.BOSS)).andReturn(70000.0)
					.times(2);
			EasyMock.expect(calcMethod.calc(Position.PROGRAMMER))
					.andReturn(50000.0);
			// Setup is finished need to activate the mock
			EasyMock.replay(calcMethod);

			calc.setCalcMethod(calcMethod);
			try {
				calc.calc();
				fail("Exception did not occur");
			} catch (PositionException e) {

			}
			calc.setPosition(Position.BOSS);
			Assert.assertEquals(70000.0, calc.calc());
			Assert.assertEquals(70000.0, calc.calc());
			calc.setPosition(Position.PROGRAMMER);
			Assert.assertEquals(50000.0, calc.calc());
			calc.setPosition(Position.SURFER);
			EasyMock.verify(calcMethod);
		}

		@Test(expected = CalcMethodException.class)
		public void testNoCalc() throws CalcMethodException, PositionException {
			calc.setPosition(Position.SURFER);
			calc.calc();
		}

		@Test(expected = PositionException.class)
		public void testNoPosition() throws CalcMethodException, PositionException {
			EasyMock.expect(calcMethod.calc(Position.BOSS)).andReturn(70000.0);
			EasyMock.replay(calcMethod);
			calc.setCalcMethod(calcMethod);
			calc.calc();
		}

		@Test(expected = PositionException.class)
		public void testCalc2() throws CalcMethodException, PositionException {
			// Setting up the expected value of the method call calc
			EasyMock.expect(calcMethod.calc(Position.SURFER)).andThrow(
					new PositionException("Don't know this guy")).times(1);

			// Setup is finished need to activate the mock
			EasyMock.replay(calcMethod);
			calc.setPosition(Position.SURFER);
			calc.setCalcMethod(calcMethod);
			calc.calc();
		}

	}
