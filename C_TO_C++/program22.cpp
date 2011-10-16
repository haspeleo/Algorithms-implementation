
/*
 * Using an array of objects
 */
using namespace std;

#include <iostream>
#include <cmath>

class Vector {
public:   
    double x; 
    double y;
    
    Vector (double a = 0, double b = 0) {
        
        x = a;
        y = b;
    }
    
    double module() {
        
        return sqrt ( x * x + y * y );
    }
        
};

int main () {
    
    Vector s [1000];
    
    Vector t[3] = { Vector(4, 5), Vector(5, 5), Vector(2, 4)};
    
    s[23] = t[2];
    
    cout <<"Module : "<< t[0].module() <<endl;        
    
    return 0;
}