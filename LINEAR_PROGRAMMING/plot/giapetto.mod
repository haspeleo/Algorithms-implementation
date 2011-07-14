# GNU MathProg file
# See http://www.ibm.com/developerworks/linux/library/l-glpk1/#assumptions
# Giapetto's problem
# This finds the optimal solution for maximizing Giapetto's profit
# run : glpsol -m giapetto.mod -o giapetto.sol

/* Decision variables */
var x1 >= 0; /* Soldier */
var x2 >= 0; /* Train */

/*Objective function */

maximize z: 3 * x1 + 2 * x2;

/* Constraints */

s.t. Finishing : 2 * x1 + x2 <= 100;
s.t. Carpentry : x1 + x2 <= 80;
s.t. Demand    : x1 <= 40;

end;
