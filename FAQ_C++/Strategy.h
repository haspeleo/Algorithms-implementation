/* 
 * File:   Strategy.h
 * Author: doghmen
 *
 * Created on 6 novembre 2011, 16:01
 */

#ifndef STRATEGY_H
#define	STRATEGY_H


#include <iostream>
using namespace std;

class IStrategie {
public:
    virtual void execute() = 0;
};


class AlgorithmeA : public IStrategie {
public:

    virtual void execute(); 
};


class AlgorithmeB : public IStrategie {
public:

    virtual void execute();
};


class AlgorithmeC : public IStrategie {
public:

    virtual void execute();
};


class Element {
private:
    IStrategie* strategie;

public:

    Element(IStrategie* strategie) : strategie(strategie) {}


    virtual void execute(); 
};


#endif	/* STRATEGY_H */

