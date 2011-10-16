
using namespace std; 

#include <iostream>
#include <cmath>

class Vector {
    
public:
    
    double x; 
    double y; 
    
    Vector (double a = 0, double b = 0);
   
    Vector operator+ (Vector );
    Vector operator- (Vector);
    Vector operator- ();
    Vector operator* (double a);
    //Vector operator* (Vector a, Vector b);
    
    double module(); 
    void setLength(double = 1);
    
};

Vector::Vector(double a, double b) {
        
    x = a; 
    y = b; 
}


Vector Vector::operator+ (Vector a) {
    
    return Vector(x + a.x, y + a.y);    
}

Vector Vector::operator* (double a) {
    
    return Vector(x * a, y * a);
}

Vector Vector::operator- (Vector a) {
    
    return Vector(x - a.x, y - a.y);
}

Vector Vector::operator- () {
    
    return Vector(-x, -y); 
}

 

double Vector::module() {
    
    return (sqrt( x * x + y * y));
}

void Vector::setLength(double a) {
    
    double length = this->module();
    
    x = x / length * a;
    y = y / length * a;
}


ostream& operator << (ostream& o, Vector a) {
    
    o << "(" << a.x << ", " << a.y << ")";
    return o;
}


Vector operator *(Vector a, Vector b) {
    
    return (a.x + b.x, a.y + b.y);
}

int main () {
    
    Vector a;
    Vector b;
    
    Vector c(3, 5);
    
    a = c * 3;
    a = b + c; 
    
    c = b -c + a + (b - a) * 7; 
    
    c = -c; 
   
   cout << "The module of vector c: " << c.module() << endl;

   cout << "The content of vector a:  " <<  a << endl;
   
   cout << "The opposite of vector a: " << -a << endl;
    
   double k = Vector(1, 1).module(); 
   
   cout <<"K contains : " << k <<endl;
   
   Vector n(0, 2); 
   Vector p(3, 2);
   Vector m = n * p; 
   
   cout <<"[" << n.x <<", "<<n.y<<"]x["<<p.x<<", "<<p.y<<"] = ";
   cout <<"["<< m.x <<", "<< m.y <<"]"<<endl;
    return 0;
}