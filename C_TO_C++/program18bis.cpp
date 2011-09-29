/*
 * The destructor in a class is often unnecessary. we can use it to do some calculations
 * whenever an instance is destroyed or output some text for debugging.
 * But if variables of the instance points to some allocated memory, 
 * then the role of the destructor is essential: it must free that memory


 * compile using : g++ -Wno-write-strings program18bis.cpp -o program18bis 
 * to get rid of: deprecated conversion from string constant to ‘char*’ warning 
 * */

using namespace std;

#include <iostream>
#include <cstring>

class Person {

    public: 
    char *name;
    int age;

    Person ( char *n = "no name", int a = 0) {
        
        name = new char [100];
        strcpy ( name, n);
        age = a;
        cout <<"Instance initialized, 100 bytes allocated"<<endl;
    }
    ~Person() {
        delete name; // delete [] name would be more academic
                     // but not vital here since the array contains 
                     // no C++ sub-objects that nees to be declared
        cout <<"Instance initialized, 100 bytes freed"<<endl;
    }

};

int main () {
    cout <<"Hello !"<<endl<<endl;

    Person a;
    cout << a.name << ", age " << a.age << endl << endl;
    
    Person b ("John");
    cout << b.name << ", age " << b.age << endl << endl;
    b.age = 21;
    cout << b.name << ", age " << b.age << endl << endl;

    Person c ("Mikki", 45);
    cout << c.name << ", age " << c.age << endl << endl;

    cout <<"Bye! "<<endl;
}
