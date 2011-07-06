/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 13 janvier 2011, 13:39
 */

#include <cstdlib>
#include<iostream>

#include "Duree.h"

using namespace std;

int main() {
 
    Duree d1(01, 30, 40), d2(01, 40, 50);
    Duree r1, r2;

    int h1 = d1.getHours(), h2 = d2.getHours();
    int m1 = d1.getMinuts(), m2 = d2.getMinuts();
    int s1 = d1.getSeconds(), s2 = d2.getSeconds();
    
    r1 = d1 + d2;
    
    if (h1 < h2) {
        cout <<"ERROR heure !"<<endl;
        }
        else if ((h1 == h2) && (m1 < m2 )) {
            cout <<"ERROR minute !"<<endl;
            }
            else if ((h1 == h2) && (m1 == m2) && (s1 < s2)) {
                    cout <<"ERROR secondes !"<<endl;
                     }
    else {
           r2 = d1 - d2;
        }

    d1.afficher();
    cout <<"+"<<endl;
    d2.afficher();
    cout <<"="<<endl;
    r1.afficher();
    r2.afficher();

    if (d1 == d2) {
        d1.afficher();
        d2.afficher();
        cout <<"dates sont identiques"<<endl;
    }
    else {
        d1.afficher();
        d2.afficher();
        cout <<"dates sont différentes"<<endl;
    }
    return 0;
}

