/* 
 * File:   Duree.h
 * Author: doghmen
 *
 * Created on 13 janvier 2011, 13:40
 */

#ifndef DUREE_H
#define	DUREE_H

class Duree {
public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    
    virtual ~Duree();

    Duree operator+(const Duree &duree);
    Duree operator-(const Duree &duree);
    bool operator==(const Duree &duree);
    
    void afficher();
    int getHours();
    int getMinuts();
    int getSeconds();

private:

    int m_heures;
    int m_minutes;
    int m_secondes;

};

#endif	/* DUREE_H */

