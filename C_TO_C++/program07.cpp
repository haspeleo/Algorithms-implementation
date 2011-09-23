
/*
 * A global variable is accessed even if another variable
 * with the same name has been declared inside the function 
 */


using namespace std;

#include <iostream>

// a here is global 
double a = 128;

int main () {
    
    // a here is local 
    double a = 256;
    
    cout << "Local a = " << a <<endl;
    cout << "Global a = "<< ::a <<endl;
    
    return 0;
}