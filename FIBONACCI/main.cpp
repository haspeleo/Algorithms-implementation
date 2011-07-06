/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 13 février 2011, 18:28
 */

#include <cstdlib>
#include<iostream>

#include <ext/hash_map>
#include <map>

std::map<int, int> results;

using namespace std;
using namespace __gnu_cxx;

int fibonacci_iterative(int n) {
    
    int a = 1, b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacci_recursive(int n) {

    if (n < 2)
        return 1;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_hashMap(int n) {
    if (n == 0 || n == 1)
        return 1;
        std::map<int, int>::iterator ii = results.find(n);
        
        if (ii != results.end())
            return ii->second;
        else
            return results[n] = fibonacci_hashMap(n - 1) + fibonacci_hashMap(n - 2);

}

int main(int argc, char** argv) {

    int n = 200;

    cout <<"*** HashMap Fibonacci ***"<<endl;
    cout <<fibonacci_hashMap(n)<<endl;


    cout <<"*** Iterative Fibonacci ***"<<endl;
    cout <<fibonacci_iterative(n)<<endl;

    cout <<"*** Recursive Fibonacci ***"<<endl;
    cout <<fibonacci_recursive(n)<<endl;

    
    return 0;
}

