/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 11 janvier 2011, 11:19
 */

#include <cstdlib>
#include "Personnage.h"

using namespace std;

int main() {

      Personnage david = Personnage("david", "Epée", 20);
      Personnage goliath = Personnage("goliath", "Sabre", 10);

    goliath.attaquer(david); // goliath attaque david
    david.afficherEtat();
    david.boirePotionDeVie(20); // david boit une potion de vie qui lui rapporte 20 de vie
    goliath.attaquer(david); // goliath réattaque david
    david.afficherEtat();
    david.attaquer(goliath); // david contre-attaque... c'est assez clair non ? ^^
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    goliath.attaquer(david);


    return 0;
}

