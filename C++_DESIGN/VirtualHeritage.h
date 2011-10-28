/* 
 * File:   VirtualHeritage.h
 * Author: doghmen
 *
 * Created on 27 octobre 2011, 16:19
 * To solve the multi-heritage problem, we add the virtual heritage modifier
 * to make the call of the constructor A() just once.
 * see http://bruno-garcia.net/www/Cours/  -- section 5.6.2.2
 */

#ifndef VIRTUALHERITAGE_H
#define	VIRTUALHERITAGE_H


class A {

public:
    A();

private:
    int a;
};

class B : virtual public A {

public:
    B();

private:
    int b;
    
};

class C : virtual public A {

public:
    C();

private:
    int c;
};


class D : virtual public A, public B, public C {

public:
    D();

private:
    int d;
};


#endif	/* VIRTUALHERITAGE_H */

