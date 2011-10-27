/* 
 * File:   VirtualHeritage.h
 * Author: doghmen
 *
 * Created on 27 octobre 2011, 16:19
 */

#ifndef VIRTUALHERITAGE_H
#define	VIRTUALHERITAGE_H


class A {

public:
    A();

private:
    int a;
};

class B : public A {

public:
    B();

private:
    int b;
    
};

class C : public A {

public:
    C();

private:
    int c;
};


class D : public A, public B, public C {

public:
    D();

private:
    int d;
};


#endif	/* VIRTUALHERITAGE_H */

