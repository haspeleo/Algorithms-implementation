
/* Variables Declaration */

var A  >=0;
var M  >=0;
var Ms >=0;

/* Objective function  */



#subject to

	s.t teneurs_matieres_premieres_A  : 13.6 * A + 4.1 * M + 5 * Ms   >= 9;
	s.t teneurs_matieres_premieres_M  : 7.1  * A + 2.4 * M + 0.3 * Ms >= 2;
	s.t teneurs_matieres_premieres_Ms : 13.6 * A + 4.1 * M + 5 * Ms   <= 6;


	s.t Dispo_A  : A  <= 11900;
	s.t Dispo_M  : M  <= 23500;
	s.t Dispo_Ms : Ms <= 750;

