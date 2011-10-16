/*
 * One or more variables in a class can be declared *STATIC*.
 * In which case, only one instance of those variables exist.
 * it is shared by all instances of the class.
 * It must be inbitialized outside the class decalaration 
 */

using namespace std;

#include <iostream>

class Vector {
public: 
    
    int x; 
    int y; 
    static int count; 
    
    Vector (double a, double b) {
        x = a;
        y = b;
        count ++;
    }
    ~Vector() {
        count --;
    }
};


int Vector::count = 0; //static variable

int main () {
    
    cout <<"Nombre d'instances de la classe Vector: " << Vector::count <<endl; 
    Vector a(2, 3); 
    cout <<"Instances number =  " << Vector::count <<endl; 
    Vector b(1, 1); 
    cout <<"Instances number =  " << Vector::count <<endl; 
   
     Vector *r, *u;

   r = new Vector(1, 0);
   cout << Vector::count << endl;
   cout <<"Instances number =  " << Vector::count <<endl; 
   u = new Vector(3, 1);
   
   cout <<"Instances number =  " << Vector::count <<endl; 
   delete r;
   cout << Vector::count << endl;
   cout <<"Instances number =  " << Vector::count <<endl; 
   delete u;
   
   cout <<"Instances number =  " << Vector::count <<endl; 
    
    
    //Vector *r, *u; 
    //r = new Vector();
    //u = new Vector();
    //cout <<"Instances number =  " << Vector::count <<endl; 
    //delete r;
    //cout <<"Instances number =  " << Vector::count <<endl; 
    //delete u;
    //cout <<"Instances number =  " << Vector::count <<endl; 
    
    
    return 0;
}