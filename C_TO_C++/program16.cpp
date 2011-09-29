/*
 * using keywords new and delete.
 * new[] and delete[] are used for arrays
 * */


using namespace std;

#include <iostream>
#include <cstring>


int main () {

    double *d = NULL; // d is a variable which contains the address
                      // of a zone where a double is located  

    d = new double;   // new allocates a zone of memory large enough 
                      // to contains a double and returns its address
                      // That address is stored in d.

    *d = 45.3;
    cout <<"Type a number"<<endl;
    cin >> *d;

    *d = *d + 5;
    cout <<" Result : "<< *d <<endl; 

    delete d;

    d = new double[15];

    d[0] = 4456;
    d[1] = d[0] + 567;

    cout <<"Content of d[1]: "<< d[1] <<endl;

    delete [] d;


    int n = 30;

    d = new double [n];
    for ( int i = 0; i < n ; i++ ) {

        d[i] = i;

    }

    delete [] d;

    char *s;
    s = new char[100];
    strcpy(s, "Hello!");
    cout << s <<endl;

    delete [] s;

    return 0;
}
