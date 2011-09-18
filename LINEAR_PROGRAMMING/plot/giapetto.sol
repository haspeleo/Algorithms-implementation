Problem:    giapetto_with_data
Rows:       5
Columns:    2
Non-zeros:  8
Status:     OPTIMAL
Objective:  z = 180 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B            180                             
<<<<<<< HEAD
     2 Finishing    NU           100                         100             1 
     3 Carpentry    NU            80                          80             1 
     4 Demand       B             20                          40 
=======
     2 Fin_hours    NU           100                         100             1
     3 Carp_hours   NU            80                          80             1
     4 Dem[soldier] B             20                          40 
     5 Dem[train]   B             60                    6.02e+23 
>>>>>>> 295db37051c1fde74c2697858f828f41f1a30747

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x[soldier]   B             20             0               
     2 x[train]     B             60             0               

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err = 2.22e-16 on column 1
        max.rel.err = 3.17e-17 on column 1
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
