/*
 * Operator overloading: used to redifine the basic symbolic operators 
 * for new kind of parameters 
 * */


using namespace std;

#include <iostream>

 struct vector {
    double x; 
    double y;
 };

//scalar product operator
vector operator * ( double a, vector b ) {
    vector r;

    r.x = a * b.x;
    r.y = a * b.y;
    
    return r;
}

ostream& operator << (ostream& o, vector a) {
    o << "(" << a.x << ", " << a.y << ")" ;
    return o;
}

int main () {
    vector k, m;
    k.x = 2;
    k.y = -1;

    m = 3.14 * k;

    cout << "(" << m.x << ", " << m.y << ")" << endl;

    vector a;
    a.x = 35;
    a.y = 23;

    cout << a ;

return 0;
}
