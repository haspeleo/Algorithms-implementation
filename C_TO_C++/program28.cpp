using namespace std;

#include <iostream>
#include <cmath>

class Vector {
    
public:
    
    int x;
    int y;
    
    Vector (double a = 0, double b = 0) {
        
        x = a;
        y = b;
    }
    
    double surface() {
        
        return fabs (x * y);
    }
   
};

class Number {
public:
    
    double z;
    
    Number (double a) {
        
        z = a;
    }
    
    int isNegative() {
        
        if ( z < 0 ) return 1;
        else         return 0;   
    }
   
};

class TriVector : public Vector, public Number {

public:
    
    TriVector(double m = 0, double n = 0, double p = 0): Vector(m, n), Number(p) {
        
    }
    
    double volume() {
        
        return fabs (x * y * z); 
    }
};


int main () {
    
    TriVector a(2, 3, -4);
    
    cout <<"Volume : "    << a.volume()    <<endl;
    
    cout <<"Surface : "   << a.surface()   <<endl;
    
    cout <<"Negativity ? : " << a.isNegative() <<endl; 
    
    return 0;
}