/*
 * define default values for function's parameters
 */

using namespace std;

#include <iostream>


double test ( double a, double b = 7) {

    return a - b;

}

int main () {
    
    cout << test (14, 5) <<endl; 
    cout << test (14) <<endl; //same as test(14,7)

    return 0;
}
