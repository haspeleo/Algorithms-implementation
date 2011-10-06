Problem:    refinery
Rows:       4
Columns:    2
Non-zeros:  6
Status:     OPTIMAL
Objective:  R = 16.96 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 R            B          16.96                             
     2 gaasoline_demand
                    NU           6.4                         6.4          2.65 
     3 oil_demand   B            3.2             3               
     4 oil_gasoline_relation
                    NL             0            -0                       -0.75 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x            B            6.4             0               
     2 y            B            3.2             0               

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 4.79e-16 on row 1
        max.rel.err = 1.37e-17 on row 1
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
