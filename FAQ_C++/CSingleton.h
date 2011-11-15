/* 
 * File:   CSingleton.h
 * Author: doghmen
 *
 * Created on 6 novembre 2011, 12:47
 */

#ifndef CSINGLETON_H
#define	CSINGLETON_H



#include <iostream>
using namespace std;


class CSingleton {
public:
    static CSingleton* getInstance();
    void destroyInstance();
    void doSomething();

private:
    CSingleton() {} // private constructor
    ~CSingleton(){}
    static CSingleton* m_pInstance;
};

#endif	/* CSINGLETON_H */

