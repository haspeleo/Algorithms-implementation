/**
 * In standard C, a struct contains only data.
 * In C++, a struct can also include functions
 * */

using namespace std;

#include <iostream>

    struct vector {
    int x; 
    int y;
    
    // a function inside a struct
    double surface () {
        double s = 0;
        if (x == 0 || y == 0) return 0;
        else 
        return ( x * y );
    }
    
    };

int main () {

    vector a;
    a.x = 3;
    a.y = 4;

    cout << "Surface of the vector: " << a.vector::surface() <<endl;


return 0;
}
