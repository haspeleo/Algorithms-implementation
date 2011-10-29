/* 
 * File:   Pile.h
 * Author: doghmen
 *
 * Created on 28 octobre 2011, 12:00
 * Généric template class for Pile
 */

#ifndef PILE_H
#define	PILE_H

const int MAX = 1024;

template <typename T> class Pile {
private:
    int taille;
    int nbElements;
    T *tab;
    T *tos;
    void clonage(const Pile&);
    void destruction();

public:

    Pile(int taille = 32) {

        tab = new T[taille];
        tos = tab - 1;
        nbElements = 0;
    }

    Pile& operator=(const Pile& p) {
	
	if(this != &p) {
	    destruction();
	    clonage(p);
	}
	return *this;
    }
    
    ~Pile() {

	destruction();
    }

    void push(T e) {

        ++tos;
        *tos = e;
        ++nbElements;
    }

    void pull() {

        --tos;
        --nbElements;
    }

    T& top() const {

        return *tos;
    }

    const T& top() {

        return *tos;
    }

    bool isEmpty() {

        return (nbElements == 0);
    }

    bool isFull() {

        return (nbElements == MAX);
    }

};

template <class T>
void Pile<T>::clonage(const Pile<T> &unePile) {
    taille = unePile.taille;
    nbElements = unePile.nbElements;

    tab = new T[taille];

    memcpy(tab, unePile.tab, sizeof (T) * nbElements);

    tos = tab + nbElements - 1;
}


template <class T>
void Pile<T>::destruction(void) {
    delete [] tab;
    tab = 0;
    tos = 0;
}


#endif	/* PILE_H */

