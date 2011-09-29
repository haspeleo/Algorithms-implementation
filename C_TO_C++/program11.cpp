/*
 * Exceptions in C++ 
 */


using namespace std;
#include <iostream>
#include <cmath>




int main(int argc, char** argv) {

    
    int a, b;
    
    cout <<"Type a number: "<<endl; 
    cin >> a;
    
    try {
        if ( a > 100 ) throw 100;
        if ( a < 10 ) throw 10;
        throw a / 3;
    } catch (int result) {
        
        cout <<"Result is : "<< result <<endl;
        b = result + 1;
    }
    
    cout <<"b contains : "<< b <<endl;
    
    //another example of exception use
    
    char zero [] = "zero"; 
    char pair [] = "pair";
    char notprime [] = "not prime";
    char prime [] = "prime";
    
    try {
        if ( a == 0) throw zero;
        if (( a / 2) * 2 == a ) throw pair;
        for (int i = 3; i < sqrt (a); i++) {
            if ( ( a / i ) * i == a ) throw notprime;            
        }
        throw prime;
    } catch ( char * conlusion ) {
        //cout <<" The number you typed : " << conclusion <<endl;
    }
    

    
    return 0;
}

