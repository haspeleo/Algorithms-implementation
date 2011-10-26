#include "Point.h" 

int Point::nbPoints = 0;

Point::Point(int abs, int ord) {

    abscisse = abs;
    ordonnee = ord;

}

Point::~Point() {

    nbPoints --;
}

int Point::X() const {
    
    return abscisse;
}

int Point::Y() const {

    return ordonnee;
}

void Point::deplacerDe(int dx, int dy) {

    abscisse = dx; 
    ordonnee = dy;
}

void Point::deplacerVers(int incx, int incy) {
    
    abscisse += incx; 
    ordonnee += incy;
}

void Point::afficher (Point p) {

	cout <<"(x, y) = (" << p.abscisse <<", "<< p.ordonnee <<")"<<endl;
    }
