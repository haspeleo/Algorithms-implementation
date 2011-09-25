/*
 * Making variable to be another 
 */


using namespace std;

#include <iostream>


double *silly_function() {
    
    static double r = 342;
    return &r;
    
}

double *biggest (double *r, double *s) {
    
    return ( *r > *s ? r : s);
}

double &biggest (double &r, double &s) {
    
    return (r > s ? r : s);
    
}

void change (double *r, double s) {
    
    *r = 100;
     s = 200;
}

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
    
    cout <<"*** Translation from C++ to C "<<endl;
 
    
    k = 3;
    m = 4; 
    
    change (&k, m);
    
    cout <<"[" << k <<","<< m << "]"<<endl;
    
    
    cout <<"*** A reference can be used to let a function return a variable"<<endl;
    
    k = 3; 
    m = 7;
    cout <<" initially [k, m ] = [" << k <<","<< m << "]"<<endl;
    
    cout <<"Compare and affect: "<<endl;
    biggest (k, m) = 10;
    
    cout <<"[" << k <<","<< m << "]"<<endl;
    
    cout <<"Compare and increment: "<<endl;
    biggest (k, m) ++;
    
    cout <<"[" << k <<","<< m << "]"<<endl;
    
    // A translation from C++ to C will be: 
    // double *biggest (double *r, double *s)
    // the call will be: (*(biggest(&k, &m))) = 10;
    
    k = 3;
    m = 4;
    
    cout <<" initially [k, m ] = [" << k <<","<< m << "]"<<endl;
    
    (*(biggest (&k, &m))) = 10;
    cout <<"Compare and affect -- C manner: "<<endl;
    
    cout <<"[" << k <<","<< m << "]"<<endl;
    
    cout <<"Compare and increment -- C manner "<<endl;
    ((*(biggest (&k, &m)))) ++; 
    cout <<"[" << k <<","<< m << "]"<<endl;
    
    
    
    cout <<"The silly function: "<<endl; 
    
    double *c = NULL;
   
    c = silly_function();
    double &d = *c; // Now b is the double which a points!
    
    d += 1;
    d = d * d;
    d +=4;
    
    cout <<"Silly result: " << a <<endl;
    cout <<"Contents of *a, b and r = "<< d <<endl;
    
    
    
    return 0;
}