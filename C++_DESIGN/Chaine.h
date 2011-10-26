/* 
 * File:   Chaine.h
 * Author: doghmen
 *
 * Created on 26 octobre 2011, 17:43
 */
#include <string.h>

#ifndef CHAINE_H
#define	CHAINE_H

class Chaine {

private:

    int longueur;
    int capacite;
    char* tableau;

public:

    Chaine(int taille = 16): longueur(0), capacite(taille) { //constructeur par defaut

	if (taille) 
	
	    tableau = new char [taille];
	else
	    tableau = 0;
    }


    Chaine (char* pStr) {

	if(pStr) {
	    int taille = strlen(pStr);
	    longueur = capacite = taille;
	}
    }







};



#endif	/* CHAINE_H */

