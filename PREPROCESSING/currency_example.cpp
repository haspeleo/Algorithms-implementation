/* example to show how to use preprocessor directives
 * 2 way to use #define 
 * 1) write # define USA to activate USA
 * 2) use g++ -DUSA currency_example.cpp -o currency_example to activate USA
 *   
 */

//#define USA 
//#define FR

#include <iostream>
#include <cstdlib> 

using namespace std;

#ifdef USA
#define currency_rate 1.2
#endif

#ifdef FR
#define currency_rate 1.9
#endif



int main () {

    int rs;
    rs = 10 * currency_rate;
    cout <<rs<<endl;

return 0;
}

