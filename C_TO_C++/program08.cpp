/*
 * Making variable to be another 
 */


using namespace std;

#include <iostream>


void change (double &r, double s) {
    
    r = 100;
    s = 200;
}


int main () {
    
    double a = 3.14;
    
    double &b = a;
    cout << "b = " << b <<endl;
    b= 89;
    
    cout <<"*** Operation double &a = b <=> double *b = &a; "<<endl;
    cout <<"*** Reference b and variable a are married on that line ;-)"<<endl;
    cout <<"a contains = "<< a <<endl;
    
    cout <<"*** References can be used to allow a function to modify a calling variable"<<endl;
    
    double k, m;
    k = 3;
    m = 4;
    
    change (k, m);
    
    cout <<"[" << k <<","<< m << "]"<<endl;
    
    
    
    
    return 0;
}