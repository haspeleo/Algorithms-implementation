
using namespace std; 
#include <iostream>



class Vector {

public:
    int x; 
    int y;
    
    Vector(int a = 0, int b = 0) {
        
        x = a;
        y = b; 
    }
    
    double surface();
};

double Vector::surface() {
    
    return x * y; 
}



int main () {
    
    
    Vector v(2, 3);
  
    cout <<"Surface : " << v.surface() <<endl;
    
    return 0;
}