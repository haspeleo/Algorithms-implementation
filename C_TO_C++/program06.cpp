/*
 * Decalaration of a variable inside a loop
 */

using namespace std;


#include <iostream>

int main () {
    
    int i;
    i = 487;  // Simple declaration of i
    
    for (int i = 0; i < 4; i++) {
        
        cout <<"i = "<< i <<endl;
    }
    
    // you can get a compiler complaint if you do not initialise i outside the for loop:
    // error: name lookup of ‘i’ changed for ISO ‘for’ scoping
    // (if you use ‘-fpermissive’ G++ will accept your code)
    
    cout <<"Inially i was : "<< i <<endl;
    
    return 0;
}