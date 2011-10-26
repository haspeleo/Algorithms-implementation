/* 
 * File:   Point.h
 * Author: doghmen
 *
 * Created on 23 octobre 2011, 20:24
 */
#include <iostream>

using namespace std;

#ifndef POINT_H
#define	POINT_H

class Point {

private:
    int abscisse;
    int ordonnee; 
    static int nbPoints;
    

public:

    Point (int abs, int ord); 
    ~Point();

    int X() const; 

    int Y() const; 

    void deplacerVers (int incx, int incy); 

    void deplacerDe (int dx, int dy);

    void afficher (Point p); 

};

#endif	/* POINT_H */

