/*
http://www.gamedev.net/page/resources/_/technical/general-programming/the-c-pimpl-r1794
*/

//In myClass.h

class MyClassImp;                    // forward declaration of Pimpl
 
class MyClass
{
public:
   MyClass ();
   ~MyClass();
 
   MyClass( const MyClass &rhs );   // undefined for simplicity
   MyClass& operator=( MyClass );
 
   void  Public_Method();
 
private:
   MyClassImp *pimpl_;              // the Pimpl
};



// In MyClass.cpp

#include "MyClass.h"
 
class MyClassImp
{
public:
   void   Private_Method()  {} 	// dummy private function
 
   int    private_var_;            // a private variable
};
 
MyClass::MyClass()  :  pimpl_( new MyClassImp() )
{
}
 
MyClass::~MyClass()
{
   delete  pimpl_;
}
 
void   MyClass::Public_Method()
{
   pimpl_->Private_Method();      // do some private work
 
   pimpl_->private_var_  = 3;
}
