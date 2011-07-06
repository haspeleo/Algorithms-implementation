/* 
 * File:   Duree.cpp
 * Author: doghmen
 * 
 * Created on 13 janvier 2011, 13:40
 */
#include<iostream>

#include "Duree.h"
using namespace std;

Duree::Duree(int heures, int minutes, int secondes):m_heures(heures), m_minutes(minutes), m_secondes(secondes) {}

Duree::~Duree() {}

void Duree::afficher() {
    cout <<"Date: "<<m_heures<<"h:"<<m_minutes<<"m:"<<m_secondes<<"s"<<endl;
}
int Duree::getHours() {
    return m_heures;
}
int Duree::getMinuts() {
    return m_minutes;
}
int Duree::getSeconds() {
    return m_secondes;
}


Duree Duree::operator+(const Duree &duree) {
   int heures = m_heures;
    int minutes = m_minutes;
    int secondes = m_secondes;

    // 1 : ajout des secondes
    secondes += duree.m_secondes; // Exceptionnellement autoris� car m�me classe
    // Si le nombre de secondes d�passe 60, on rajoute des minutes et on met un nombre de secondes inf�rieur � 60
    minutes += secondes / 60;
    secondes %= 60;

    // 2 : ajout des minutes
    minutes += duree.m_minutes;
    // Si le nombre de minutes d�passe 60, on rajoute des heures et on met un nombre de minutes inf�rieur � 60
    heures += minutes / 60;
    minutes %= 60;

    // 3 : ajout des heures
    heures += duree.m_heures;

    // Cr�ation de l'objet resultat et retour
    Duree resultat(heures, minutes, secondes);
    return resultat;


}
Duree Duree::operator-(const Duree &duree) {
    int heures = m_heures;
    int minutes = m_minutes;
    int secondes = m_secondes;

    secondes -= duree.m_secondes;
    if (secondes < 0) {
        secondes += 60;
        minutes -= 1;
    }

    minutes -= duree.m_minutes;
    if (minutes < 0) {
        minutes += 60;
        heures -= 1;
    }
   
    heures -= duree.m_heures;

    Duree resultat(heures, minutes, secondes);
    return resultat;
}
bool Duree::operator==(const Duree &duree) {
    if (m_heures == duree.m_heures
        && m_minutes == duree.m_minutes
        && m_secondes == duree.m_secondes )
        return true;
    else
        return false;
}