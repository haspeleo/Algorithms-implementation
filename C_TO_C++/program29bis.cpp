
/*
 * Polymorphism and multiple inheritence
 */

using namespace std;


#include <iostream>
#include <cmath>

class Octopus {

public:

    virtual double module() = 0;
};

class CuttleFish {

    virtual int test() = 0;
};

class Vector: public Octopus, public CuttleFish {

public:

    double x; 
    double y;

    double module() {

        return sqrt ( x * x + y * y);
    }

    int test () {
        
        if ( x > y ) return 1;
        else 	     return 0;
    }
};

int main () {

			
    
    return 0;
}
