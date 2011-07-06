/* 
 * File:   Arme.cpp
 * Author: doghmen
 * 
 * Created on 11 janvier 2011, 16:55
 */

#include <iostream>

#include "Arme.h"

std::string nomArme;
int degatsArme;

Arme::Arme() : nomArme("Epée rouillée"), degatsArme(10) {}

Arme::Arme(string nomArme, int degatsArme) : nomArme(nomArme), degatsArme(degatsArme) {}

Arme::~Arme() {}

void Arme::changerArme(string nomNouvelleArme, int degatsNouvelleArme) {
        nomArme = nomNouvelleArme;
        degatsArme = degatsNouvelleArme;
    }
void Arme::afficher() {
    cout<<"Arme: "<<nomArme<<"(Dégats: "<<degatsArme<<")"<<endl;
    }

int Arme::getDegats() const {
    return degatsArme;
}
