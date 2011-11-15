/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 5 novembre 2011, 12:08
 */

#include <cstdlib>

#include "CSingleton.h"

using namespace std;

#include <iostream>
using namespace std;
 
class IStrategie
{
public:
        virtual void execute() = 0;
};
 
class AlgorithmeA: public IStrategie
{
public:
        void execute()
        {
                cout << "Traitement A" << endl;
        }
};
 
class AlgorithmeB: public IStrategie
{
public:
        void execute()
        {
                cout << "Traitement B" << endl;
        }
};
 
class AlgorithmeC: public IStrategie
{
public:
        void execute()
        {
                cout << "Traitement C" << endl;
        }
};
 
class Element
{
private:
        IStrategie* strategie;
 
public:
        Element(IStrategie* strategie) : strategie(strategie)
        {
        }
 
        void execute()
        {
                this->strategie->execute();
        }
};
 

int main(int argc, char** argv) {

    cout <<"*** Pattern Singleton ***"<<endl;	
    CSingleton* inst = CSingleton::getInstance();
    inst->doSomething();
    inst->destroyInstance();


    cout <<"*** Pattern Strategy ***"<<endl;

        AlgorithmeA algoA;
        AlgorithmeB algoB;
        AlgorithmeC algoC;
 
        Element elementA(&algoA);
        Element elementB(&algoB);
        Element elementC(&algoC);
 
        elementA.execute(); // L'élément A va effectuer le traitement A
        elementB.execute(); // L'élément B va effectuer le traitement B
        elementC.execute(); // L'élément C va effectuer le traitement C
 

    return 0;
}

