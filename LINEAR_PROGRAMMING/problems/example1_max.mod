
/* Decision variables */

    var x >=0;
    var y >=0;

/* Objective function */

    maximize z : 3 * x + 4 * y;

/* Constraints */

    s.t. constraint_1 : x + 2 * y <= 14;
    s.t. constraint_2 : 3 * x - y >=  0;
    s.t. constraint_3 : x - y     <=  2;

end;
Hassen
