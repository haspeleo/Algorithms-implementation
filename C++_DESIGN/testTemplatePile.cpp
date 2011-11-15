/* 
 * File:   testTemplatePile.cpp
 * Author: doghmen
 *
 * Created on 28 octobre 2011, 12:11
 */

#include <cstdlib>
#include <iostream>

#include "Pile.h"

using namespace std;


typedef Pile<int> PileInt;

int main(int, char**) {


    PileInt pile;

    for (int i = 0; i < 32; i++) {

        pile.push(2 * i);
    }

    while (!pile.isEmpty()) {

	cout <<"=>"<< pile.top() <<endl;

        pile.pull();
    }


    return 0;
}

