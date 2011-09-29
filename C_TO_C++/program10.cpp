/*
 * few lines of code and no for loop or the like => declare int inline function 
 * That somewhat like a macro
 * the + : the program will be faster 
 * the - : the program will be bigger : full code's funtion will be everywhere
 */


using namespace std;

#include <iostream>
#include <cmath>

// function declared inline    
inline double hypothenuse ( double a, double b) {
    return sqrt ( a * a + b * b );
    
}

int main () {
    
    double k = 6, m =9;
    
    //The next two lines produces exactly the same code
    cout <<sqrt (k * k + m * m) <<endl;
    cout <<hypothenuse (k, m) <<endl; 
    
    return 0;
}