using namespace std;

#include <iostream>

class Vector {

protected:

    double x;
    double y;
    

public:

    void setX(int n) {

	x = n;
    }
    
    void setY(int n){

	y = n;
    }

    double surface() {

	double s = 0;
	s = x * y;
	if ( s < 0) s = -s; 
	return s;
    }
};


int main () {

    Vector a;

    a.setX(2);
    a.setY(3);

    cout <<"Surface of a = " << a.surface() <<endl;
    

    return 0;
}

