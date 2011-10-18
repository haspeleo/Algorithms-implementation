using namespace std;

#include <iostream>
#include <fstream>

int main() {

    fstream f;

    f.open("test.txt", ios::out);

    f << "I write some text in test.txt" << endl;
    double a = 2.71;

    f << "A value in my file : " << a << endl;

    f.close();

    char c;

    cout << "Let's see what we had written int the file " << endl;
    cout <<"-------"<<endl;

    f.open("test.txt", ios::in);

    while (!f.eof()) {

        f.get(c);
        cout << c;
    }

    f.close();

    return 0;
}
