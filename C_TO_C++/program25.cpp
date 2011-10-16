using namespace std;

#include <iostream>


class Vector {
public:
	double x; 
	double y;
	const static double PI = 3.1415927;

Vector (double a = 0, double b = 0) {

	x = a; 
	y = b;
}	

double cylinderVolume () {

	return x * x / 4 * PI * y;
}

};


int main () {


	cout <<"The value of PI: "<< Vector::PI <<endl;
	Vector k (3, 4);
	cout <<"Result : "<< k.cylinderVolume()<<endl;

	return 0;
}
