/* 
 * File:   Rectangle.h
 * Author: doghmen
 *
 * Created on 9 février 2011, 10:56
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H
template<typename T>
class Rectangle;

//prototyper la fonction avant la définition de la classe
template<typename T>
bool operator==(const Rectangle<T>& a, const Rectangle<T>& b);

template<typename T> class Rectangle {
public:
    Rectangle();
    Rectangle(T gauche, T droite, T haut, T bas)
    : m_gauche(gauche), m_droite(droite), m_haut(haut), m_bas(bas){}
    
    Rectangle(const Rectangle& orig);
    virtual ~Rectangle(){};

    T hauteur() const {
        return m_haut - m_bas;
    }

    bool estContenu(T x, T y) {
        return ( x >= m_gauche && x <= m_droite
                && y >= m_bas && y <= m_haut);
    }

private:
    //les cotes du rectangle
    T m_gauche;
    T m_droite;
    T m_haut;
    T m_bas;
    friend bool operator==<>(const Rectangle<T>& a, const Rectangle<T>& b);
};

template<typename T>
bool operator==(const Rectangle<T>& a, const Rectangle<T>& b) {
        return (a.m_droite    == b.m_droite &&
                a.m_gauche == b.m_gauche &&
                a.m_haut   == b.m_haut &&
                a.m_bas    == b.m_bas);
    }

#endif	/* RECTANGLE_H */



