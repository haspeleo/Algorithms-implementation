#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


const int AlphabetSize = 26;

using namespace std;

void listAlphabet() {

    for (int k = 0; k < AlphabetSize; k++) {

        char currLetter = 'a' + k;
        cout <<currLetter<< " ";
    }
    cout <<" * * * "<<endl;
}

void countLetters(string filename) {

    ifstream in;
    in.open(filename.c_str());
    if(in.fail()) {
        cout <<"failed to read the file "<<filename<<endl;
        exit(1);
    }

    //must initialise the contents of the vector
    vector<int> counter(AlphabetSize, 0);

    string line; 

    while (true) {

        getline(in, line);
        if(in.fail()) break;

        //lower case all characters
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        for(int j = 0; j < line.length(); j++) {
            int index = line[j] - 'a';
                if(index >= 0 && index < AlphabetSize) { //if 0<= index < AlphabetSize then it is in [a-z]
                    int prevTotal = counter[index];
                    counter[index] = prevTotal + 1;
                }
            }

        }

for (int k = 0; k < AlphabetSize; k++) {
    char currLetter = 'a' + k;
    cout <<currLetter<<" : "<<counter[k]<<endl;
}


in.close();

}

int main () {

listAlphabet();

vector<int> counter;

countLetters("alphabet.txt");

return 0;
}
