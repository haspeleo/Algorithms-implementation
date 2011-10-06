# Porblem from book programmation linéaire Christelle Guéret
# Page 43
#
# glpsol -m simpleExample2.mod -o simpleExample2.sol

/* variables decision */
var x1 >= 0; /* ciment 1er choix */
var x2 >= 0; /* ciment 2eme choix */

/* Objective function */
maximize z : 4 * x1 + 3 * x2;


/* Constraints */
s.t. Constraint_1     : 3 * x1 + 4 * x2 <= 12;
s.t. Constraint_2     : 4 * x1 + 2 * x2 <= 9;

end;
