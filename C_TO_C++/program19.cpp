/*
 *If you cast an object like a vector, everything will happen correctly.
* For example, vector k = (4,7), after a cast m = k,  m = (4, 7)
* the values k.x and k.y have simply been copied to m.x and m.y.
*
* For object person, writing p = r will not ensure that p will be a correct copy of r.
* Otherwise, p.name will point to the same physical character string as r.name.
* The former character string pointed by p.name is lost and become a memory zombie.
*
* The result will be catastrophic: a mess of pointers and a loss of data.
* Solution: COPY CONSTRUCTOR AND OVERLOAD OF THE =OPERATOR
* */

using namespace std;

#include <iostream>
#include <cstring>


class Person {

    public:
    char *name;
    int age;

    Person( char * n = "no name", int a = 0) {
        name = new char [100]; 
        strcpy(name, n);
        age = a;
    }

    ~Person () {
        delete [] name;
    }

    Person ( const Person &s) { // The COPY CONSTRUCTOR
        name = new char [100];
        strcpy ( name, s.name);
        age = s.age;
    }

    Person& operator= ( const Person &s ) {
        strcpy ( name, s.name);
        age = s.age;
        return *this;
    }


};

    void modifyPerson ( Person& h) {
        h.age += 7;
    }

    Person computePerson ( Person h ) {
        h.age += 7;
        return h;
    }


int main () {

   Person p;
   cout << p.name << ", age " << p.age << endl << endl;
   // output: no name, age 0

   Person k ("John", 56);
   cout << k.name << ", age " << k.age << endl << endl;
   // output: John, age 56

   p = k;
   cout << p.name << ", age " << p.age << endl << endl;
   // output: John, age 56

   p = Person ("Bob", 10);
   cout << p.name << ", age " << p.age << endl << endl;
   // output: Bob, age 10

   // Neither the copy constructor nor the overload
   // of = are needed for this operation that modifies 
   // p since just the reference towards p is passed to
   // the function modify_Person:  
   modifyPerson (p);
   cout << p.name << ", age " << p.age << endl << endl;
   // output: Bob, age 17

   // The copy constructor is called to pass a complete 
   // copy of p to the function compute_Person. The 
   // function uses that copy to make its computations
   // then a copy of that modified copy is made to 
   // return the result. Finally the overload of = is 
   // called to paste that second copy inside k:
   k = computePerson (p);
   cout << p.name << ", age " << p.age << endl << endl;
   // output: Bob, age 17
   cout << k.name << ", age " << k.age << endl << endl;
   // output: Bob, age 24


}
