/*
 * Derived classes:
 *  a class can be derived from another class. The new class inherits 
 * the variables and the methods of the base clas.
 * Additonal variables and/or methods can added.
 */

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
    
    double module() {
        
        return sqrt(x * x + y * y);
    }
    
    double surface() {
        
        return x * y; 
    }
    
};

class TriVector : public Vector {
public:
    double z;
    
    TriVector(double m = 0, double n = 0, double p = 0): Vector (m,n) {
        
        z = p; // Vector constructor is called before TriVector 
               // constructor, with parameters m and n  
    }
    
    TriVector (Vector a) {
       
        x = a.x;
        y = a.y;
        z = 0;
    }
    
    double module() {
        
        return sqrt ( x * x + y * y + z * z);
    }
    
    double volume () {
        
        return this->surface() * z;
    }
};

int main () {
    
    Vector a (4, 5); 
    TriVector b(1, 2, 3);
    
    
    return 0;
}