/*
 * Inputs and outputs performed using cout << and cin >>
 */

using namespace std;

#include <iostream>

int main () {
    
    int age;
    char name [100];
    
    cout <<"This is a simple program. "<<endl;
    
    cout <<"Type your age: "; 
    cin >> age;
    
    cout << "Type your name: " ;
    cin >> name;
    
    
    cout <<"Hello "<<name<<", you are "<<age<<" years old."<<endl;
    
    cout <<"Bye"<<endl;
    
    return 0;
}