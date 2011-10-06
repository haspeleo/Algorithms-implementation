Problem:    example2_max
Rows:       7
Columns:    2
Non-zeros:  11
Status:     OPTIMAL
Objective:  z = 18.8 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B           18.8                             
     2 constraint_1 NU             7                           7           1.4 
     3 constraint_2 B             13             4               
     4 constraint_3 NL            -5            -5                        -1.8 
     5 constraint_domain_1
                    B              1            -0               
     6 constraint_domain_2
                    B              1                           5 
     7 constraint_domain_3
                    B              6            -0               

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x            B              1                             
     2 y            B              6                             

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 3.33e-16 on row 1
        max.rel.err = 8.45e-18 on row 1
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err = 2.22e-16 on column 2
        max.rel.err = 3.00e-17 on column 2
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
