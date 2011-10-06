Problem:    calculators
Rows:       6
Columns:    2
Non-zeros:  8
Status:     OPTIMAL
Objective:  Z = 650 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 Z            B            650                             
     2 expected_demand_x
                    NL           100           100                          -2 
     3 expected_demand_y
                    B            170            80               
     4 production_capacity_1
                    B            100                         200 
     5 production_capacity_2
                    NU           170                         170             5 
     6 shipping_contract
                    B            270           200               

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x            B            100             0               
     2 y            B            170             0               

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
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
