#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class StringBuilder {
public:

    template<typename T>
    StringBuilder& operator() (const T& t) {
	std::ostringstream oss;
	oss << t;
	String_ += oss.str();

	return *this;
    }

    //string print(StringBuilder s) {

//	return (string)s;
  //  }


private:
    std::string String_;
    
};


int main (int, char **) {


	StringBuilder s;
	s("Salut, j'ai")(27)("ans");
//	cout << (string)s <<endl;

    return 0;
}