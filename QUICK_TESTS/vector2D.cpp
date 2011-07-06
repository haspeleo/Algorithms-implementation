#include <iostream>
#include <vector>

using namespace std;

int main () {

    typedef vector<vector<int> > intMatrix;
    intMatrix M;

    vector<vector<int> > v2d;
    //Creating a 3x5 matrix using 2d vector
    vector<int> colums(5, 99);
    vector<vector<int> > v2d2(3, colums);

    for(int i = 0; i < v2d2.size(); i++) {
        for (int j = 0; j < v2d2[i].size(); j++) {
            cout <<v2d2[i][j]<<" ";
            cout << endl;
        }
        
    }


return 0;
}
