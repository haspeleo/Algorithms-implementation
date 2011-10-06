/* Decisions variables */

    var x >= 0;
    var y >= 0;

/* Objective function: maximize revenue */
/* Warning: we loose money producing x and get profit producing y ! */
    maximize Z : -2 * x + 5 * y;

/* constrainsts */


    s.t. expected_demand_x      : x >= 100;
    s.t. expected_demand_y      : y >= 80;
    s.t. production_capacity_1  : x <= 200;
    s.t. production_capacity_2  : y <= 170;
    s.t. shipping_contract      : x + y >= 200;

end;

