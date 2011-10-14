/* Variables declaration */

printf "\n Giapetto Problem\n\n";

	var x1 >= 40; 
	var x2 >= 0;
 
/* Objective function: Profit */

	maximize ProfitOfProduction : 3 * x1 + 2 * x2; 


/* Constraints */

	s.t.  Finishing_constraint  : 2 * x1 + x2 <= 100;
	s.t.  Carpentry_constraint  : x1 + x2 <= 80;
end;
