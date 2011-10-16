/*
 * When a method is applied to an instance, that method 
 * may use the instance's varables, modify them.
 * Sometimes it is necessary to know the adress od the adress od the instance
 * No problem, the keyword *this* is intended to that purpose
 * 
 */

using namespace std;

#include<iostream>
#include<cmath>


class Vector {
public:
    
    int x; 
    int y; 
    
    Vector (int a = 0, int b = 0) {
        
        x = a; 
        y = b;
    }
    ~Vector() {
        
        cout <<" Vector class objects destruction ..."<<endl;
    }
    
    Vector(Vector& v) {
        x = v.x;
        y = v.y;
    }
    
    Vector& operator=(Vector& v) {
        
        x = v.x;
        y = v.y;
        
        return *this;
    }
    
    double module() {
        
        return sqrt( x * x + y * y);
    }
    
    double setLength( double a = 1) {
        
        double length; 
        length = this->module();
      
        x = x / length * a;
        y = y / length * a;
        
        //x /= length * a;
        //y /= length *a;        
    }
    
    
};

int main () {
    
    
    Vector c (3, 5);

    Vector p; 
    p = c;
    
   cout << "The module of vector c: " << c.module() << endl;

   c.setLength(2);            // Transforms c in a vector of size 2.

   cout << "The module of vector c: " << c.module() << endl;

   c.setLength();             // Transforms b in an unitary vector.

   cout << "The module of vector c: " << c.module() << endl;

    
   
    return 0;
}