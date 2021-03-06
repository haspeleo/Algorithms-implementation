
/* Decisions varibles*/

    var x; 
    var y;

/* Objective function */

     maximize z : -0.4 * x + 3.2 * y; 

/* Constraints */

    s.t. constraint_1 : x + y     <= 7; 
    s.t. constraint_2 : x + 2 * y >= 4;
    s.t. constraint_3 : x - y + 5 >= 0; 
    s.t. constraint_domain_1 : x >= 0;
    s.t. constraint_domain_2 : x <= 5;
    s.t. constraint_domain_3 : y >= 0;
end;
