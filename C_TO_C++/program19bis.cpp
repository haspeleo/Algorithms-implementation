
using namespace std; 

#include <iostream>
#include <cstring>

class Person {

public:  
    int age; 
    char* name; 
    
    Person(int a = 0, char* n = "anonyme") {
        
        name = new char[50];
        strcpy(name, n);
        age = a;        
    }
    
    ~Person() {
        
        delete [] name;
        cout <<"Person object successfully cleared..."<<endl;
    }
    
    Person(const Person &s) {
        
        name = new char[50];
        strcpy(name, s.name);
        age = s.age;
    }
    
    Person& operator= (const Person s) {
        
        strcpy(name, s.name);
        age = s.age;
        return *this;
    }
  
};


  
    void modifyPerson(Person &h) {
        
        h.age += 7; 
    }
    
    Person computePerson(Person h) {
        
        h.age += 7;
        return h;
    }
    
    void printPerson(Person p) {
        
        cout <<"Person name : "  << p.name <<endl;
        cout <<"Person age  : "  << p.age  <<endl;
    }


int main () {
    
    Person p;
    
    printPerson(p);
    
    Person k (22, "Bob");
    
    p = k; 
    
    printPerson(p);
    
    modifyPerson(p);
    
    
    return 0;
}