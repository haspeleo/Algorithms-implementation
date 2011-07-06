//stringstream::str
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	stringstream oss;
	string mystr;

	oss << "Simple string";
	mystr = oss.str();

	cout << mystr;

return 0;
}
