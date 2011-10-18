using namespace std;

#include <iostream>



int sign(double n) {        // methode to control sign assigned o attributes@ 

    if ( n >= 0) return 1;
    else return -1;
}


class Vector {

protected:

    double x;
    double y;
    

public:

    void setX(int n) {

	x = sign(n) * n;
    }
    
    void setY(int n){

	y = sign(n) * n;
    }

    double surface() {

	double s = 0;
	s = x * y;
	if ( s < 0) s = -s; 
	return s;
    }

    double getX() {

	return x;
    }

    double getY() {

	return y;
    }
};


int main () {

    Vector a;

    a.setX(2);
    a.setY(3);


    cout << "Vector : V[x="<< a.getX() <<", y= "<< a.getY() <<"]"<<endl;

    cout <<"Surface of a = " << a.surface() <<endl;

    Vector b;
    b.setX(-3);
    b.setY(1);

    
    cout << "Vector : V[x="<< b.getX() <<", y= "<< b.getY() <<"]"<<endl;
    cout <<"Surface of a = " << b.surface() <<endl;

    return 0;
}

