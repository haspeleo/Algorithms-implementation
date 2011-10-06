Problem:    example2_min
Rows:       5
Columns:    2
Non-zeros:  9
Status:     OPTIMAL
Objective:  z = -2 (MINimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B             -2                             
     2 constraint_1 B              5                           7 
     3 constraint_2 B              5             4               
     4 constraint_3 B              5            -5               
     5 constraint_domain_x
                    NU             5                           5          -0.4 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x            B              5             0               
     2 y            NL             0             0                         3.2 

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 1.11e-16 on row 1
        max.rel.err = 2.22e-17 on row 1
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err = 0.00e+00 on column 0
        max.rel.err = 0.00e+00 on column 0
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
