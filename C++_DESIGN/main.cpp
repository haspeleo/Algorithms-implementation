/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 23 octobre 2011, 15:36
 */

#include <cstdlib>
#include <iostream>

#include "Point.h"

using namespace std;


int main(int argc, char** argv) {

    // argv[0] est le nom d'invocation de l'éxecutable 
    cout <<"EXE: "<< argv[0] <<endl; 


    for (int i = 0; i < argc; i++) {
	
    	cout <<"Argument["<< i <<"] = "<< argv[i] <<endl;

    } 

    Point p(2, 3);
    p.afficher(p);
    p.deplacerDe(1, 1);
    p.deplacerVers(5, 2);
    p.afficher(p);
    

    return 0;
}

