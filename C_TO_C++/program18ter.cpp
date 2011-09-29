/*
 * Array class definition.
 * it contains a method that overloads the [] operator and outputs a reference(&) 
 * is used in order to generate an error if an attempt is made to access data 
 * outside the limits of an array
 * */

using namespace std;

#include <iostream>
#include <cstdlib>

class Array {

    public:
    int size;
    double *data;

    Array (int s ) {

        size = s;
        data = new double [s];
    }

    ~Array() {
        delete [] data;
    }

    double & operator [] ( int i ) {
        
        if ( i < 0 || i >= size ) {
            cerr <<endl << "Out of bounds" <<endl;
            exit (EXIT_FAILURE);
        }
        else return data[i];
    }
};




int main () {
    
    Array t (5);
    t[0] = 45;
    t[4] = t[0] + 6;

    cout << t[4]<<endl;
    t[10] = 7; // error: the array contain only 5 slots

    return 0;
}

