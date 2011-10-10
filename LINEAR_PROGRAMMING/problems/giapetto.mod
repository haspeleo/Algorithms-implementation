/* Variables declaration */

	var x1 >= 40; 
	var x2 >= 0;
 
/* Objective function: Profit */

	maximize Z : 3 * x1 + 2 * x2; 


/* Constraints */

	s.t.  finishing : 2 * x1 + x2 <= 100;
	s.t.  carpentry : x1 + x2 <= 80;
end;
