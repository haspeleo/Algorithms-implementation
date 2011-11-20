#include <iostream>
#include <ostream>

using namespace std;


class Complex {
    public:
        explicit Complex( double real, double imaginary = 0 )
          : real_(real), imaginary_(imaginary) {}

        Complex& operator+=( const Complex& other ) {
            real_ += other.real_;
            imaginary_ += other.imaginary_;
            return *this;
        }

        Complex& operator++() {
            ++real_;
            return *this;
        }

        const Complex operator++( int ) {
            Complex temp = *this;
            ++(*this);
            return temp;
        }

        ostream& print( ostream& os ) const {
            return os << "(" << real_
                      << "," << imaginary_ << ")";
        }

    private:
        double real_, imaginary_;
        friend ostream& 
        operator<<( ostream& os, const Complex& c );
    };

    const Complex operator+( const Complex& lhs,
                             const Complex& rhs ) {
        Complex ret( lhs );
        ret += rhs;
        return ret;
    }

    ostream& operator<<( ostream& os,
                         const Complex& c ) {
        return c.print(os);
    }


int main (int, char **) {

	Complex a (2, 3);
	Complex b (1, 1);
	
	Complex c = a + b;

	cout << a << endl; 
	cout << b << endl;


return 0;
}
