#include <iostream>
#include <string>
#include <vector>


using namespace std;


void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout <<v[i]<<" ";
    }
    cout <<" "<<endl;
}

vector<int> findmatching(string text, string pattern) {

    vector<int> positions;
    int textLength = text.length();
    int patternLength = pattern.length();
   
    for (int i = 0; i < textLength; i++) {
        int j = 0;
        while (j < patternLength && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == patternLength) {   
            positions.push_back(i + 1);
        } 
    }    
    return positions;

}

void rabin_karp(string text, string pattern, int hash) {
    
}

/*********************************************************************/
/*             sub string pattern matching                           */
/*********************************************************************/

int main(){

    vector<int> positions;
    string text = "yeyvey";
    string pattern = "y";
    cout <<"TEXT: "<<text<<endl;
    cout <<"Fetching for pattern <"<<pattern<<">"<<endl;

    positions = findmatching(text, pattern);
        if (positions.size() != 0) {
                cout <<"pattern found at positions : "<<endl;
                printVector(positions);
        }
        else
                cout <<"end of search: pattern Not found !"<<endl;    
    
return 0;
}
