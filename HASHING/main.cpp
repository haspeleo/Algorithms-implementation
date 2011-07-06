/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 11 mars 2011, 15:32
 * http://www.brpreiss.com/books/opus4/
 * http://www.mysqlperformanceblog.com/2006/06/09/why-mysql-could-be-slow-with-large-tables/
 * http://users.cis.fiu.edu/~weiss/dsaa_c++/code/
 * http://www.cs.princeton.edu/~rs/ //book algorithmes en C++ Robert Sedgewick
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int hash_folding(string word, int tableSize) {


    int sum = 0;
    for(int i = 0; i < word.length(); i++) {
        sum += word[i];
        cout <<word[i]<<" ";
    }
    return sum % tableSize;
}


int main(int argc, char** argv) {

    string s1 = "ABC";
    string s2 = "CZB";
    int i1 = hash_folding(s1, 100);
    int i2 = hash_folding(s2, 100);

    cout <<"Hashing values for "<<s1<<" - "<<s2<<" are : "<<i1<<" - "<<i2<<endl;

    return 0;
}

