/*
 * What is a class: it is a struct that keeps it's data hiddden.
 * Only the methods of the class can access the data.
 * You cannot access the data directly, unless authorized by the public: directive
 * */

using namespace std;

#include <iostream>

class vector {

    public:

    double x;
    double y;

    double surface() {
        double s;
        s = x * y;
        if ( s < 0) s = -s;
        return s;
    }

};



int main () {

    vector a;
    a.x = 3;
    a.y = 4;

    cout << "The surface of a: " << a.surface() <<endl;

    return 0;
}


