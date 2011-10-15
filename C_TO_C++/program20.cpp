
using namespace std; 
#include <iostream>



class Vector {

public:
    int x; 
    int y;
    
    Vector(int x = 0, int y = 0) {
        
        this->x = x;
        this->y = y; 
    }
    
//};

double surface() {
    
    return x * y; 
}

};

int main () {
    
    
    Vector v(2, 3);
    //v.x = 2;
    //v.y = 3;
    
    cout <<"Surface :" << v.surface() <<endl;
    
    return 0;
}