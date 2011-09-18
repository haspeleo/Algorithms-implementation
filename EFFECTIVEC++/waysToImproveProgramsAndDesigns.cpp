
Introdution:
//*------------------------------------------------
//* Declaration: Tells the compiler about the name and type of something 
//*------------------------------------------------

extern int x;

std::size_t numDigits( int number );

class Widget;

template <typename T> class GraphNode;

Note:
size_t:
size_t corresponds to the integral data type returned by the language operator sizeof and is defined in the <cstring> header file (among others) as an unsigned integral type.
In <cstring>, it is used as the type of the parameter num in the functions memchr, memcmp, memcpy, memmove, memset, strncat, strncmp, strncpy and strxfrm, which in all cases it is used to specify the maximum number of bytes or characters the function has to affect.

It is also used as the return type for strcspn, strlen, strspn and strxfrm to return sizes and lengths.


//*------------------------------------------------
//Definition: provides compiler with the details a declaration omits.
//*------------------------------------------------

int x;

std::size_t numDigits ( int number ) {

std::size_t digitsSoFar = 1;

while ((number /= 10) != 0) 
++ digitsSoFar;

return digitsSoFar;
}

class Widget {  //class definition
public:
Widget();
~Widget();
//...
};

template<tyepame T> class GraphNode { //template definition
public:
GraphNode();
~GraphNode();
}


//*------------------------------------------------
//Initialisation: giving an object it's first value
//*------------------------------------------------

class A {
public:
A(); //default constructor

};




