/*
 * Class derivation allows you to construct more complex classes built from base
 * classes. There is another application of derivation:
 * allowing programmer to write generic functions
 * 
 */

using namespace std;
#include <iostream>
#include <cmath>

class Octopus {
    
public:
    
    virtual double module() = 0;
    // =0 means that this function is not defined.
    //making it's class instances to not be declared 
    
};

double biggestModule (Octopus &a, Octopus &b, Octopus &c) {
    
    double r = a.module();
    if ( b.module() > r ) r = b.module();
    if ( c.module() > r ) r = c.module();
    
    return r;
}

class Vector : public Octopus {
    
public:
    double x;
    double y;
    
    Vector(double a = 0, double b = 0) {
        
        x = a; 
        y = b;
    }
    
    double module() {
        
        return sqrt( x * x + y * y );
    }
      
};

class Number : public Octopus {
    
public:
    
    double n;
    
    Number(double a = 0) {
        
        n = a;
    }
    
    double module () {
        
        if ( n >= 0 ) return n; 
        else          return -n;  
    }
};


int main () {
    
    Vector k(1, 2), m(6, 7), n(100, 0);
    Number p(5),    q(-3),   r(-150);
    
    
    cout <<"Biggest module: "<<biggestModule(k, m, n)<<endl;
    cout <<"Biggest module: "<<biggestModule(p, q, r)<<endl;
    
    cout <<"Biggest module: "<<biggestModule(p, q, n)<<endl;
    
    return 0;
}