/* 
 * File:   Arme.h
 * Author: doghmen
 *
 * Created on 11 janvier 2011, 16:55
 */

#ifndef ARME_H
#define	ARME_H
#include <string>

using namespace std;

class Arme {

private:

   std::string nomArme;
   int degatsArme;

public:
   Arme();
   Arme(string nomArme, int degatsArme);

   ~Arme();

public:
    void changerArme(string nomArme, int degatsArme);
    void afficher();
    int  getDegats() const;
};

#endif	/* ARME_H */

