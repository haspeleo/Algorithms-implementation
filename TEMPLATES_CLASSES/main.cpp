/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 9 février 2011, 10:55
 */

#include <cstdlib>
#include<iostream>

#include "Rectangle.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //marre d'écrire Rectangle<double>
    typedef Rectangle<double> Rectd;

    
    Rectd d(1.0, 4.5, 3.1, 5.2);
    Rectangle<int> r(2, 3, 5, 4);

    cout <<"Hauteur du Rectangle<int>: "<<r.hauteur()<<endl;
    cout <<"Hauteur du Rectangle<double>: "<<d.hauteur()<<endl;
    bool answer = true;
    (answer) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    answer = false;
    answer ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    int x = 1, y = 2;
    r.estContenu(x, y) ? cout <<"Point in the Rectangle"<<endl : cout <<"Point out of the Rectangle"<<endl;
    
    Rectangle<double> r1(2.1, 3.5, 4.7, 6.2);
    Rectangle<double> r2(2.1, 3.5, 4.7, 6.2);
    Rectangle<double> r3(2.0, 3.0, 4.0, 6.0);

    (r1 == r2) ? cout<<"Equal rectangles"<<endl : cout<<"NOT equal rectangles"<<endl;
    (r1 == r3) ? cout<<"Equal rectangles"<<endl : cout<<"NOT equal rectangles"<<endl;
    return 0;
}

