Problem:    bicycleProductionPlanification
Rows:       14
Columns:    36
Non-zeros:  95
Status:     OPTIMAL
Objective:  z = 35040000 (MINimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 z            B      3.504e+07                             
     2 Iventory_Balance_Equation
                    B        -218000                       28000 
     3 Stockage_month_2
                    NS         15000         15000             =            20
     4 Stockage_month_3
                    NS         15000         15000             =            40
     5 Stockage_month_4
                    NS         25000         25000             =            60
     6 Stockage_month_5
                    NS         33000         33000             =            80
     7 Stockage_month_6
                    NS         40000         40000             =           100
     8 Stockage_month_7
                    NS         45000         45000             =           120
     9 Stockage_month_8
                    NS         45000         45000             =           140
    10 Stockage_month_9
                    NS         26000         26000             =           160
    11 Stockage_month_10
                    NS         14000         14000             =           160
    12 Stockage_month_11
                    NS         25000         25000             =           160
    13 Stockage_month_12
                    NS         30000         30000             =           160
    14 max_production
                    NU         30000                       30000           -30

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 xn1          NL             0             0                         160
     2 xn2          NL             0             0                         140
     3 xn3          NL             0             0                         120
     4 xn4          NL             0             0                         100
     5 xn5          NL             0             0                          80
     6 xn6          NL             0             0                          60
     7 xn7          NL             0             0                          40
     8 xn8          NL             0             0                          20
     9 xn9          NL             0             0                       < eps
    10 xn10         NL             0             0                       < eps
    11 xn11         NL             0             0                       < eps
    12 xn12         B          30000             0               
    13 xs1          NL             0             0                         160
    14 xs2          NL             0             0                         140
    15 xs3          NL             0             0                         120
    16 xs4          NL             0             0                         100
    17 xs5          NL             0             0                          80
    18 xs6          NL             0             0                          60
    19 xs7          NL             0             0                          40
    20 xs8          NL             0             0                          20
    21 xs9          B          26000             0               
    22 xs10         B          14000             0               
    23 xs11         B          25000             0               
    24 xs12         B              0             0               
    25 s1           B         218000             0               
    26 s2           B         203000             0               
    27 s3           B         188000             0               
    28 s4           B         163000             0               
    29 s5           B         130000             0               
    30 s6           B          90000             0               
    31 s7           B          45000             0               
    32 s8           NL             0             0                       < eps
    33 s9           NL             0             0                          20
    34 s10          NL             0             0                          20
    35 s11          NL             0             0                          20
    36 s12          NL             0             0                         180

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err. = 0.00e+00 on row 0
        max.rel.err. = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err. = 0.00e+00 on row 0
        max.rel.err. = 0.00e+00 on row 0
        High quality

KKT.DE: max.abs.err. = 0.00e+00 on column 0
        max.rel.err. = 0.00e+00 on column 0
        High quality

KKT.DB: max.abs.err. = 0.00e+00 on row 0
        max.rel.err. = 0.00e+00 on row 0
        High quality

End of output
