#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

const int FirstNarcissism = 9999;

void narcissism() {

for(int integer = 0; integer < FirstNarcissism ; integer++) {

    string number = "";
    //convert integer to string
    stringstream ss;
    ss << integer;
    number = ss.str();

    int sum = 0;
    int numberSize = number.length();
    for(string::iterator it = number.begin(); it < number.end(); it++) {
    
    //for(int j = 0; j < numberSize; j++) {

        string nbString = "";
        nbString += *it;
        //convert string to integer
        istringstream iss(nbString);
        int n;
        iss >> n;
        sum += pow(n, numberSize);
    }

    if(sum == integer) 
        cout <<"Narcist integer = "<<integer<<endl;
    }

}

int main() {

narcissism();

return 0;
}
