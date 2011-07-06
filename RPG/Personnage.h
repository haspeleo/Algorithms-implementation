/* 
 * File:   Personnage.h
 * Author: doghmen
 *
 * Created on 11 janvier 2011, 11:12
 */

#ifndef PERSONNAGE_H
#define	PERSONNAGE_H

#include <string>

#include "Arme.h"

using namespace std;

class Personnage {
public:
    
    Personnage(); //Constructeur
    Personnage(std::string m_nom, std::string m_nomArme, int degatsArme);//surcharge du Constructeur

    Personnage(const Personnage &personnageACopier);

    ~Personnage(); //Destructeur 
    
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    void afficherEtat();

// Tout ce qui suit est privé (inaccessible depuis l'extérieur)
    private:

    string m_nom;
    int m_vie;
    int m_mana;
    Arme *m_arme;
    
};
#endif	/* PERSONNAGE_H */

