
#include <iostream>

#include "VirtualHeritage.h"

using namespace std;


A::A() {

    cout <<"=> Constructeur de A"<<endl;
}

B::B() : A() {

    cout <<"=> Constructeur de B"<<endl;
}

C::C() : A() {

	cout <<"=> Constructeur de C"<<endl;    
}

D::D() : A(), B(), C() {

    cout <<"=> Constructeur de D"<<endl;
}