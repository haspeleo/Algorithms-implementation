package income;

import income.method.ICalcMethod;
import income.CalcMethodException;
import income.PositionException;

public class IncomeCalculator {

	private ICalcMethod calcMethod;
	private Position position;

	public void setCalcMethod(ICalcMethod calcMethod) {
		this.calcMethod = calcMethod;
	}

	public void setPosition(Position position) {
		this.position = position;
	}

	public double calc() throws CalcMethodException, PositionException {
		
		if (calcMethod == null) {
			throw new CalcMethodException("CalcMethod not yet maintained");
		}
		if (position == null) {
			throw new PositionException("Position not yet maintained");
		}
		return calcMethod.calc(position);
	}
}
