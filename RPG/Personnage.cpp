/* 
 * File:   Personnage.cpp
 * Author: doghmen
 * 
 * Created on 11 janvier 2011, 11:12
 */

#include<string>
#include<iostream>

#include "Personnage.h"

using namespace std;

  /***************************************************************************/
  /* attributs privés de Personnage                                          */
  /***************************************************************************/
    int m_nom;
    int m_vie;
    int m_mana;
  /***************************************************************************/
  /* Constructeurs et Destructeur                                            */
  /***************************************************************************/
    Personnage::Personnage() :m_vie(100), m_mana(100){
        m_arme = new Arme();
    }
        //un autre constructeur
    Personnage::Personnage(string m_nom, string nomArme, int degatsArme): m_nom(m_nom), m_vie(100), m_mana(100){
        m_arme = new Arme(nomArme, degatsArme);
    }
    //constructeur en copie
    Personnage::Personnage(const Personnage &personnageACopier) { //const pour interdire de modifier l'objet
        m_vie = personnageACopier.m_vie;
        m_mana  = personnageACopier.m_vie;
        m_arme  = new Arme(*(personnageACopier.m_arme));
    }

        //le destructeur
    Personnage::~Personnage() {
        delete m_arme;
    }

  /***************************************************************************/
  /* methodes publiques de Personnage                                        */
  /***************************************************************************/

    void Personnage::attaquer(Personnage &cible) {
        cible.recevoirDegats(m_arme->getDegats());
    }
    void Personnage::recevoirDegats(int nbDegats) {
        m_vie -= nbDegats;
        if (m_vie < 0)
            m_vie = 0;
    }
    void Personnage::changerArme(string nouvelleArme, int degatsNouvelleArme) {
        m_arme->changerArme(nouvelleArme, degatsNouvelleArme);
    }
    void Personnage::boirePotionDeVie(int quantitePotion) {
        cout <<m_nom <<"> potion de vie + "<<quantitePotion<<endl;
        m_vie += quantitePotion;
        if (m_vie > 100 )
            m_vie = 100;
    }
    bool Personnage::estVivant() {
        if (m_vie > 0)
            return true;
        else
            return false;
    }
    void Personnage::afficherEtat() {

        cout <<"Guerrier: "<<m_nom<<";Vie: "<<m_vie<<"; Mana: "<<m_mana<<"Arme: "<<endl;
        m_arme->afficher();
    }
