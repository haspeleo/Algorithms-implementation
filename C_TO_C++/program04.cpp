
/*
 * Variables can be declared anywhere in the code
 * and can be encapsulated between "{  }" block
 */

using namespace std;

#include <iostream>


int main () {
    
    double a;
    cout <<"Type a number" ;
    cin >> a;
    
    
    {
        int a = 1;
        a = a * 10 + 4; 
        cout <<"Local number = "<< a <<endl;
    }
    
    cout <<"You typed: "<< a <<endl;
    
    
    return 0;
}
