# GNU MathProg file
# See Livre programmation linéaire christelle Guéret et al. page 131
# 
# 
# exemple de lancement: glpsol -m modele.mod -o solution.sol

/* Decision variables */
/* bicyvlettes à produire en heures normales pour le mois i */

var xn1 >= 0; 
var xn2 >= 0; 
var xn3 >= 0; 
var xn4 >= 0; 
var xn5 >= 0; 
var xn6 >= 0; 
var xn7 >= 0; 
var xn8 >= 0; 
var xn9 >= 0; 
var xn10 >= 0; 
var xn11 >= 0; 
var xn12 >= 0; 

var xs1 >= 0; 
var xs2 >= 0; 
var xs3 >= 0; 
var xs4 >= 0; 
var xs5 >= 0; 
var xs6 >= 0; 
var xs7 >= 0; 
var xs8 >= 0; 
var xs9 >= 0; 
var xs10 >= 0; 
var xs11 >= 0; 
var xs12 >= 0;


var s1 >= 0; 
var s2 >= 0; 
var s3 >= 0; 
var s4 >= 0; 
var s5 >= 0; 
var s6 >= 0; 
var s7 >= 0; 
var s8 >= 0; 
var s9 >= 0; 
var s10 >= 0; 
var s11 >= 0; 
var s12 >= 0;

/*Objective function : */

minimize z: (130 * xn1 + 160 * xs1 + 20 * s1) + (130 * xn2 + 160 * xs2 + 20 * s2) + (130 * xn3 + 160 * xs3 + 20 * s3) + (130 * xn4 + 160 * xs4 + 20 * s4) + (130 * xn5 + 160 * xs5 + 20 * s5) + (130 * xn6 + 160 * xs6 + 20 * s6) + (130 * xn7 + 160 * xs7 + 20 * s7) + (130 * xn8 + 160 * xs8 + 20 * s8) + (130 * xn9 + 160 * xs9 + 20 * s9) + (130 * xn10 + 160 * xs10 + 20 * s10) + (130 * xn11 + 160 * xs11 + 20 * s11) + (130 * xn12 + 160 * xs12 + 20 * s12);

/* Constraints */

s.t. Iventory_Balance_Equation : xn1 + xs1 + 2000 - 30000 - s1 <= 0;

s.t. Stockage_month_2  : xn2 + xs2 + s1     - 15000 - s2  = 0;
s.t. Stockage_month_3  : xn3 + xs3 + s2     - 15000 - s3  = 0;
s.t. Stockage_month_4  : xn4 + xs4 + s3     - 25000 - s4  = 0;
s.t. Stockage_month_5  : xn5 + xs5 + s4     - 33000 - s5  = 0;
s.t. Stockage_month_6  : xn6 + xs6 + s5     - 40000 - s6  = 0;
s.t. Stockage_month_7  : xn7 + xs7 + s6     - 45000 - s7  = 0;
s.t. Stockage_month_8  : xn8 + xs8 + s7     - 45000 - s8  = 0;
s.t. Stockage_month_9  : xn9 + xs9 + s8     - 26000 - s9  = 0;
s.t. Stockage_month_10 :  xn10 + xs10 + s9  - 14000 - s10 = 0;
s.t. Stockage_month_11 :  xn11 + xs11 + s10 - 25000 - s11 = 0;
s.t. Stockage_month_12 :  xn12 + xs12 + s11 - 30000 - s12 = 0;

s.t. max_production  : xn1 + xn2 + xn3 + xn4 + xn5 + xn6 + xn7 + xn8 + xn9 + xn10 + xn11 + xn12 <= 30000; 

end;
