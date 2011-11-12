
#include <iostream>

using namespace std; 

class A {
public:
    void F1() {
	cout <<"A::F1()"<<endl;
    }
    virtual void F2() {

	cout <<"A::F2()"<<endl; 
    }
};

class B : public A {
public:
    void F1() {

	cout <<"B::F1()"<<endl;
    }
    void F2() {

	cout <<"B::F2()"<<endl; 
    }

};


int main (int, char **) {

    A a; 
    a.F1(); //affiche A::F1()
    a.F2(); //affiche A::F2()

    B b;  
    b.F1(); //affiche B::F1()
    b.F2(); //affiche B::F2()

    a = b;
    a.F1(); //affiche A::F1()
    a.F2(); //affiche A::F2()

    A* ptr_a = &b;
    ptr_a->F1(); //affiche A::F1()
    ptr_a->F2(); //affiche B::F2()

    A& ref_a = b;
    ref_a.F1(); //affiche A::F1()
    ref_a.F2(); //affiche B::F2()

 return 0;   
}