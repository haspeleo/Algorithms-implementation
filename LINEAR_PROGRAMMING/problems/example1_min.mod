
/* www.purplemath.com/modules/linprog.htm */

/* Decision variables */

    var x ; /* when positivity constraint is not explicitely written  */
    var y ; /* x and y are authorized to have negative values */

/* Objective function */

    minimize z : 3 * x + 4 * y;

/* Constraints */

    s.t. constraint_1 : x + 2 * y <= 14; /* glpk could convert inequalities to equalities */
    s.t. constraint_2 : 3 * x - y >=  0;
    s.t. constraint_3 : x - y     <=  2;

end;
Hassen
