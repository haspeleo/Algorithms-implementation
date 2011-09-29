/*
 * A class is a struct with hidden data only accessible via methods
 * and if declared public:
 * */

using namespace std;

#include <iostream>

class vector {

    public:
    double x;
    double y;

    vector ( double a = 0, double b = 0 ) { // not overloading the constructor is
    // a good practice. The best is to declare one construtor and give it default parameters
    // whenever possible.
        x = a; 
        y = b;    
    }

};

int main () {
    
    vector k;  // vector() is called
    cout << "vector k: " << k.x << ", " << k.y <<endl; 

    vector m (45, 2);  //vector (double, double ) is called 
    cout << "vector m: " << m.x << ", " << m.y <<endl; 

    k = vector (23, 2);  // vector created, copied to k, then erased
    cout << "vector k: " << k.x << ", " << k.y <<endl; 
    
    return 0;
}
