# Porblem from book programmation linéaire Christelle Guéret
# Page 5
#
# glpsol -m simpleExample.mod -o simpleExample.sol

/* variables decision */
var c1 >= 0; /* ciment 1er choix */
var c2 >= 0; /* ciment 2eme choix */

/* Objective function */
maximize z : 50 * c1 + 70 * c2;


/* Constraints */
s.t. Broyage      : 40 * c1 + 20 * c2 <= 360;
s.t. Calcination  : 30 * c1 + 30 * c2 <= 480;

end;
