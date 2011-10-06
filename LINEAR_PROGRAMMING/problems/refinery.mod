
/* Decisions variables */

    var x >= 0;
    var y >= 0;

/* Objective function: maximize revenue */

    maximize R : 1.9 * x + 1.5 * y;

/* constrainsts */

    s.t. gaasoline_demand : x <= 6.4;
    s.t. oil_demand : y >= 3;
    s.t. oil_gasoline_relation : x - 2 * y >= 0;

end;

