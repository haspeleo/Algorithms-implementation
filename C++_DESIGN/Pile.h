/* 
 * File:   Pile.h
 * Author: doghmen
 *
 * Created on 28 octobre 2011, 12:00
 * Généric template class for Pile
 */

#ifndef PILE_H
#define	PILE_H

template <typename T> class Pile {
private:

    int taille;
    T element;

public:
    Pile(int taille = 32);
    ~Pile();
    void push(T& e);
    void pull() const;
    T& top() const;
    bool isEmpty();
    bool isFull();

};

#endif	/* PILE_H */

