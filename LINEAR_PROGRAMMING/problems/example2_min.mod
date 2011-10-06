
/* Decisions varibles*/

    var x >= 0; 
    var y >= 0;

/* Objective function */

     minimize z : -0.4 * x + 3.2 * y; 

/* Constraints */

    s.t. constraint_1 : x + y     <= 7; 
    s.t. constraint_2 : x + 2 * y >= 4;
    s.t. constraint_3 : x - y + 5 >= 0; 

    s.t. constraint_domain_x : x <= 5; 

end;
